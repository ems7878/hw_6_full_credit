#include "library.h"
#include "publication.h"
#include "enums.h"
#include "dialogs.h"

#include <iostream>
#include <vector>
#include <string>
#include <gtkmm.h>

using namespace std;

int main(int argc, char *argv[]) {

  Gtk::Main kit(argc, argv);

  Library library;

  string cmd_str = "";
  int usernum = -1;
  while (usernum != 0) {
    string menu, title;
    menu = "=================================\n"
           "CSE1325 Library Management System\n"
           "=================================\n\n"
           "Publications\n"
           "------------\n"
           "(1) Add publication\n"
           "(2) List all publications\n"
           "(3) Check out publication\n"
           "(4) Check in publication\n\n"
           "Utility\n"
           "-------\n"
           "(9) Help\n"
           "(0) Exit\n\n";

    title = "Main menu";

    cmd_str = Dialogs::input(menu, title);
    if (cmd_str == "CANCEL") break;

    usernum = atoi(cmd_str.c_str());


    if (usernum == 1) {
      string title, author, copyright, isbn;
      int temp;
      Genre genre;
      Media media;
      Age age;

      cout << "Enter title.";
      getline(cin, title);

      cout << "Enter author. ";
      getline(cin, author);

      cout << "Enter copyright date. ";
      getline(cin, copyright);

      for (int i = 0; i < genres.size(); ++i)
        cout << "  " << i << ") " << genres[i] << endl;
      cout << "Enter genre. ";
      cin >> temp;
      genre = (Genre) temp;
      cin.ignore();

      for (int i = 0; i < medias.size(); ++i)
        cout << "  " << i << ") " << medias[i] << endl;
      cout << "Enter media type. ";
      cin >> temp;
      media = (Media) temp;
      cin.ignore();

      for (int i = 0; i < ages.size(); ++i)
        cout << "  " << i << ") " << ages[i] << endl;
      cout << "Enter age category. ";
      cin >> temp;
      age = (Age) temp;
      cin.ignore();

      cout << "Enter ISBN.";
      getline(cin, isbn);

      try {
        library.add_publication(Publication(title, author, copyright, genre, media, age, isbn));
      } catch (Publication::invalid_checkout e) {
        cerr << "Error in adding. Request not carried out." << endl;
      }

   }
   if (usernum >= 2 && usernum <= 4) {
      cout << endl;
      cout << "----------------------------" << endl;
      cout << "List of Library Publications" << endl;
      cout << "----------------------------" << endl;
      for (int i=0; i<library.number_of_publications(); ++i)
        cout << i << ") " << library.publication_to_string(i) << endl;

   }
   if (usernum == 3) {
      int pubnum;
      string pname;
      string pphone;

      cout << "Enter publication number.";
      cin >> pubnum;
      cin.ignore();

      cout << "Enter name of patron. ";
      getline(cin, pname);
      cout << "Enter patron phone number.";
      getline(cin, pphone);

      try {
        library.check_out(pubnum, pname, pphone);
      } catch (Publication::invalid_checkout e) {
        cerr << "The requested publication is checked out." << endl;
      }

   }
   if (usernum == 4) {
      int pubnum;
      cout << "Enter publication number. ";
      cin >> pubnum;
      cin.ignore();

      try {
        library.check_in(pubnum);
      } catch (Publication::invalid_checkout e) {
        cerr << "The requested publication is checked out." << endl;
      }

   }
   if (usernum == 9) {
      cout << "Please enter a number from 1-4. Click 0 to exit." << endl;

   }
   if (usernum == 45) {
     library.easter_egg();
   }
   if (usernum < 0 || (4 < usernum && usernum < 9) || (9 < usernum && usernum < 45) || (45 < usernum)) {  //validation check
     cerr << "Invalid number entered.\n" << endl;
   }
  }
  return EXIT_SUCCESS;
}
