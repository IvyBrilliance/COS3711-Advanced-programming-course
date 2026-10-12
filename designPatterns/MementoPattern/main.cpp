#include <QCoreApplication>

/*
 * Memento captures an objects internal state so that it can be resotred later.
 * it is how you build Undo/Backup-restore
 * It has 3 roles: Originator, memento and caretaker
 *
 * Originator- the object whose state is saved- it creates the memento
 * Memento- a small object that just holds the saved state. it then exposes that state only to the orginiator(via friend))
 * Caretaker- whoever asks for a memento and keeps it until restor time. It never looks inside the memento.
 *
 */

// Memento: just stores the saved state( a list of strings)
class MyListMemento{
    friend class MyListWidget; // only the originator may read the state
public:
    MyListMemento(){}
private:
    void setState(QStringList s) {
        state = s;
    }
    QStringList getState() const{
        return state;
    }
    QStringList state;

};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    return a.exec();
}
