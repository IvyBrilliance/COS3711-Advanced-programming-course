
#include <QCoreApplication>
#include <QObject>
#include <QMetaProperty>
#include <QMetaObject>
#include <QDebug>
#include <QList>
#include <QByteArray>
#include <QString>
#include <QVariant>

class Box : public QObject {
    Q_OBJECT

    Q_PROPERTY(double volume READ getVolume WRITE setVolume NOTIFY volumeChanged)
    Q_PROPERTY(bool cube READ isCube WRITE setCube NOTIFY cubeChanged)

public:
    explicit Box(QObject* parent = nullptr) : QObject(parent) {}

    // Getters
    double getVolume() const {
        return volume;
    }

    bool isCube() const {
        return cube;
    }

    // Setters
    void setVolume(double v) {
        if (volume != v) {
            volume = v;
            emit volumeChanged();
        }
    }

    void setCube(bool c) {
        if (cube != c) {
            cube = c;
            emit cubeChanged();
        }
    }

signals:
    void volumeChanged();
    void cubeChanged();

private:
    double volume = 0;
    bool cube = false;
};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Box* obj = new Box;
    obj->setVolume(125.5);
    obj->setCube(true);

    // Reading every declared Box property generically
    const QMetaObject* mo = obj->metaObject();

    for (int i = mo->propertyOffset(); i < mo->propertyCount(); i++) {
        QMetaProperty prop = mo->property(i);
        QString name = prop.name();
        QString value = prop.read(obj).toString();
        // print:
        qDebug() << name << ":" << value;
    }

    obj->setProperty("urgent", "high priority"); // setting property at runtime

    // Read dynamic property
    QString u = obj->property("urgent").toString();

    //qDebug() << "Urgent:" << u;

    // Retrieve all dynamic property names
    QList<QByteArray> extras = obj->dynamicPropertyNames();

    // Loop and display dynamic properties
    for (const QByteArray& name : extras) {
        //qDebug() << name << ":" << obj->property(name.constData()).toString();
    }

    delete obj;

    return 0;
}

// Required when Q_OBJECT is declared inside main.cpp
#include "main.moc"
