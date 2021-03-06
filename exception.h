#ifndef EXCEPTION_H
#define EXCEPTION_H
//Fichier de définition des exception

class TacheException{
public:
    TacheException(const QString& message):info(message){}
    QString getInfo() const { return info; }
private:
    QString info;
};

class CalendarException{
public:
    CalendarException(const QString& message):info(message){}
    QString getInfo() const { return info; }
private:
    QString info;
};

class ProjetException{
public:
    ProjetException(const QString& message):info(message){}
    QString getInfo() const { return info; }
private:
    QString info;
};

/*! \class TimeException
        \brief Classe permettant de gérer les exceptions des classes du namespace TIME
*/

class TimeException{
public:
    //! Constructeur à partir d'une string
    TimeException(const QString& m):info(m){}
    const QString& GetInfo() const { return info; } //<! Retourne l'information stockée dans la classe
private:
    QString info;
};

//Pour commit !
#endif // EXCEPTION_H

