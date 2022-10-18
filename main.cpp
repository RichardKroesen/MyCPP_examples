#include <iostream>
#include <string>

using namespace std;

// User Interface:
namespace ViewLayer
{
    class UserInterface 
    {
    public:
        void print(string msg) {
            cout << msg << endl;
        }

        int getUserInt() {
            int userNumber;
            cin >> userNumber;
            return userNumber;
        }

    };
}

// Model Layer:
namespace ModelLayer
{
    class Storage
    {
    private:
        int counter;

    public:

        void setCounter(int nr) {
            counter = nr;
        }

        int getCounter() {
            return counter;
        }
    };
}


// System Logic Controller:
namespace Controller
{
    class businessLogic 
    {
    private:
        ViewLayer::UserInterface *ui;
        ModelLayer::Storage *model;

    public:
        businessLogic(ViewLayer::UserInterface *u, ModelLayer::Storage *s) {
            ui = u;
            model = s;
        }

        void updateCounter() {
            ui->print("Hi User!\n What number should the counter be?");  
            model->setCounter(ui->getUserInt());
            ui->print("The current counter is: " + to_string(model->getCounter()));
        }
    };
}

int main() 
{
    ViewLayer::UserInterface interface;
    ModelLayer::Storage storage;
    Controller::businessLogic logic(&interface, &storage);

    logic.updateCounter();

    return 0;
}