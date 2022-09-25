#include <iostream>
#include <list>
#include <string.h>
using namespace std;

struct Contact
{
  string name;
  int phone;
  string company;
};

void cadastrar(list<Contact> *agenda)
{
  Contact contact;

  cout << "\nCadastrando novo contado\n";

  cout << "Nome: ";
  cin >> contact.name;

  cout << "Telefone: ";
  cin >> contact.phone;

  cout << "Empresa: ";
  cin >> contact.company;

  agenda->push_back(contact);
}

bool consultar(list<Contact> *agenda)
{
  list<Contact>::iterator it;

  string name;

  cout << "\nPesquisar: ";
  cin >> name;
  cout << "Procurando de " << agenda->size() << " contado(s)...\n";

  for (it = agenda->begin(); it != agenda->end(); it++)
  {
    if (it->name == name)
    {
      cout << "\nContato encontrado!\n";

      cout << "Nome: " << it->name << endl;
      cout << "Phone: " << it->phone << endl;
      cout << "Empresa: " << it->company << endl;
      return true;
    }
  }
  cout << "Contato nÃ£o encontrado";
  return false;
}

bool alterar(list<Contact> *agenda)
{
  list<Contact>::iterator it;

  string name;

  cout << "\nPesquisar: ";
  cin >> name;

  cout << "Procurando de " << agenda->size() << " contado(s)...\n";

  for (it = agenda->begin(); it != agenda->end(); it++)
  {
    if (it->name == name)
    {
      cout << "\nContato encontrado!\n";

      cout << "Nome: " << it->name << endl;
      cin >> it->name;
      cout << "Phone: " << it->phone << endl;
      cin >> it->phone;
      cout << "Empresa: " << it->company << endl;
      cin >> it->company;

      cout << "Alterado com sucesso.";

      return true;
    }
  }
  cout << "Contato nÃ£o encontrado";
  return false;
}

bool deletar(list<Contact> *agenda)
{
  list<Contact>::iterator it;

  string name;

  cout << "\nPesquisar: ";
  cin >> name;
  cout << "Procurando de " << agenda->size() << " contado(s)...\n";
  for (it = agenda->begin(); it != agenda->end(); it++)
  {
    if (it->name == name)
    {
      agenda->erase(it);
      cout << "Contato excluÃ­do com sucesso!";
      return true;
    }
  }
  cout << "Contato nÃ£o encontrado";
  return false;
}

int main()
{
  list<Contact> agenda, *pagenda;
  pagenda = &agenda;

  int option;

  cout << "\nBem vindo a Agenda";

  while (1)
  {
    cout << "\n\n1 - Cadastrar\n";
    cout << "2 - Consultar\n";
    cout << "3 - Alterar\n";
    cout << "4 - Deletar\n";
    cout << "5 - Sair\n";

    cin >> option;

    switch (option)
    {
    case 1:
      cadastrar(pagenda);
      break;
    case 2:
      consultar(pagenda);
      break;
    case 3:
      alterar(pagenda);
      break;
    case 4:
      deletar(pagenda);
      break;
    case 5:
      cout << "Fechando...";
      break;
    default:
      cout << "\nEscolha invÃ¡lida\n";
    }
  }

  cout << "Hello World!\n";
}