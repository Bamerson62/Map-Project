int main() {
  ifstream inputFile("schedule.csv");
  if (!inputFile.is_open()) {
      cerr << "Error: Unable to open file." << endl;
      return 1;
  }

  schedule mySchedule;
  mySchedule.initSchedule(inputFile);
  inputFile.close();

  int choice;
  do {
      cout << "\nMenu:\n1. Print Schedule\n2. Find by Subject\n3. Find by Subject and Catalog\n4. Find by Instructor\n5. Exit\nEnter your choice: ";
      cin >> choice;

      string subject, catalog, instructor;
      switch (choice) {
          case 1:
              mySchedule.printSchedule();
              break;

          case 2:
              cout << "Enter Subject: ";
              cin >> subject;
              mySchedule.findBySubject(subject);
              break;
          case 3:
                          cout << "Enter Subject: ";
                          cin >> subject;
                          cout << "Enter Catalog: ";
                          cin >> catalog;
                          mySchedule.findBySubjectCatalog(subject, catalog);
                          break;

                      case 4:
                          cout << "Enter Instructor Last Name: ";
                          cin >> instructor;
                          mySchedule.findByInstructor(instructor);
                          break;

                      case 5:
                          cout << "Exiting program." << endl;
                          break;

                      default:
                          cout << "Invalid choice. Please try again." << endl;
                  }
              } while (choice != 5);

              return 0;
          }