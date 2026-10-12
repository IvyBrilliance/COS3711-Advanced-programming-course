#include <QCoreApplication>
#include <QMetaProperty>


class Box : public QObject{
    Q_OBJECT
    Q_PROPERTY(double volume READ volume WRITE setVolume )
    Q_PROPERTY(bool cube READ cube WRITE setCube )
public:
    explicit Box(QObject* parent = nullptr) : QObject(parent) {}
    double getVolume() const {
        return volume;
    }
    void setVolume(double v) {
        volume = v;
    }
    bool isCube() const {
        return cube;
    }
    void setCube(bool c){
        cube = c;
    }
private:
    double volume = 0;
    bool cube = false;
};


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // Instantiate:
    Box * obj = new Box;

    // Reading every property generically:
    const QMetaObject* mo = obj->metaObject();
    for(int i = 1; i < mo->propertyCount(); i++){
        QMetaProperty prop = mo->property(i);
        QString name = prop.name();
        QString value = prop.read(obj).toString();

    }

    // We can then set dynamic properties and display them in run time:
    obj->setProperty("urgent", "high priority"); // this will add it to only this object
    QString u = obj->property("urgent").toString(); // read it back

    // display th erun time properties only:
    QList<QByteArray> extras = obj->dynamicPropertyNames();

    // loop and print:
    for (QByteArray &name: extras){
        qDebug() << name;
    }

    return a.exec();
}

























