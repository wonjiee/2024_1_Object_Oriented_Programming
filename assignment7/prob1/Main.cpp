#include "EventScheduler.h"

void process_command(EventScheduler scheduler) {
    string command, event_type, date_string,date_string1,date_string2,date_temp, content, keyword;
    while(1) {
        cout << "$ ";
        cin >> command;
        if (command == "add") {
            cin >> event_type;
            cin >> date_string;
            getline(cin, content);
            scheduler.add_event(event_type, date_string, content);
        }
        else if (command == "find") {
            try {
                cin >> date_temp;
                int n=date_temp.find("-");
                if(n!=-1) {
                    date_string1 = date_temp.substr(0, n);
                    date_temp.erase(0, n + 1);
                    date_string2 = date_temp;
                }
                else{
                    date_string1=date_temp;
                    date_string2=date_temp;
                }
                Date d1(date_string1);
                Date d2(date_string2);
                scheduler.show_relevant_events(d1,d2);
            }
            catch (std::invalid_argument const& ex)
            {
                cout << "Invalid Date String!!" << ex.what() << '\n';
            }
        }
        else if (command == "search") {
            getline(cin, keyword);
            scheduler.search_events(keyword);
        }
        else if (command == "list") {
            scheduler.show_all_events();
        }
        else if (command == "delete") {
            int id;
            cin >> id;
            scheduler.delete_event(id);
        }
        else if(command=="save"){
            string name;
            cin>>name;
            scheduler.save_event(name);

        }
        else if (command == "exit") {
            break;
        }
    }
}

int main() {
    EventScheduler scheduler;
    scheduler.load_data_file("events.txt");
    process_command(scheduler);

    return 0;
}
