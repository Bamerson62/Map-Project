#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <iterator>
#include <sstream>
#include <utility>
using namespace std;

// scheduleItem class
class scheduleItem {
private:
    string Subject, Catalog, Section, Component, Session, Instructor;
    int Units, TotEnrl, CapEnrl;

public:
    // Constructor with default values
    scheduleItem(string subject = "", string catalog = "", string section = "", string component = "",
                 string session = "", int units = 0, int totEnrl = 0, int capEnrl = 0, string instructor = "")
        : Subject(subject), Catalog(catalog), Section(section), Component(component),
          Session(session), Units(units), TotEnrl(totEnrl), CapEnrl(capEnrl), Instructor(instructor) {}

    // Overloaded operators
    bool operator==(const scheduleItem& other) const {
        return (Subject == other.Subject && Catalog == other.Catalog && Section == other.Section);
    }

    bool operator!=(const scheduleItem& other) const {
        return !(*this == other);
        }

        bool operator>=(const scheduleItem& other) const {
            return (*this == other);
        }

        // Getter functions
        string getKey() const {
            return Subject + "_" + Catalog + "_" + Section;
        }

        string getInstructor() const { return Instructor; }

        string getSubject() const { return Subject; }

        string getCatalog() const { return Catalog; }

        // Print function
void print() const {
    cout << Subject << "\t" << Catalog << "\t" << Section << "\t" << Component << "\t"
         << Session << "\t" << Units << "\t" << TotEnrl << "\t" << CapEnrl << "\t" << Instructor << endl;
}
};

// schedule class
class schedule {
private:
map<string, scheduleItem> scheduleMap;

public:
// Initialize schedule from file
void initSchedule(ifstream& file) {
    string line;
    getline(file, line); // Skip the header row
    while (getline(file, line)) {
        stringstream ss(line);
        string Subject, Catalog, Section, Component, Session, Instructor;
        int Units, TotEnrl, CapEnrl;

        getline(ss, Subject, ',');
        getline(ss, Catalog, ',');
        getline(ss, Section, ',');
        getline(ss, Component, ',');
        getline(ss, Session, ',');

        string temp;
        getline(ss, temp, ',');
        Units = stoi(temp);
        getline(ss, temp, ',');
        TotEnrl = stoi(temp);
        getline(ss, temp, ',');
        CapEnrl = stoi(temp);

        getline(ss, Instructor, ',');

        scheduleItem item(Subject, Catalog, Section, Component, Session, Units, TotEnrl, CapEnrl, Instructor);
        addEntry(item);
    }
    }

    // Add an entry to the map
    void addEntry(const scheduleItem& item) {
        scheduleMap[item.getKey()] = item;
    }

    // Print all entries
    void printSchedule() const {
        cout << "Subject\tCatalog\tSection\tComponent\tSession\tUnits\tTotEnrl\tCapEnrl\tInstructor" << endl;
        for (const auto& entry : scheduleMap) {
            entry.second.print();
        }
    }

    // Find by subject
    void findBySubject(const string& subject) const {
        for (const auto& entry : scheduleMap) {
            if (entry.second.getSubject() == subject) {
                entry.second.print();
            }
        }
    }

    // Find by subject and catalog
    void findBySubjectCatalog(const string& subject, const string& catalog) const {
        for (const auto& entry : scheduleMap) {
            if (entry.second.getSubject() == subject && entry.second.getCatalog() == catalog) {
                            entry.second.print();
                        }
                    }
                }

                // Find by instructor
                void findByInstructor(const string& instructor) const {
                    for (const auto& entry : scheduleMap) {
                        if (entry.second.getInstructor() == instructor) {
                            entry.second.print();
                        }
                    }
                }
            };