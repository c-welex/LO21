#ifndef EVENEMENT_H
#define EVENEMENT_H

#include<iostream>
#include<typeinfo>
#include "timing.h"
#include "tache.h"

using namespace std;
using namespace TIME;

class CalendarException{
public:
    CalendarException(const QString& message):info(message){}
    QString getInfo() const { return info; }
private:
    QString info;
};

class Activite {        //Ajout de statut aux activités ?
private:
    QString titre;
    Duree duree;
public:
    Activite(const QString&  s, const Duree d): titre(s), duree(d){};
    QString getTitre()const{return titre;};
    Duree getDuree()const {return duree;};
};

class Evt {    //Virtuelle pure
private:
    Date date;
    Horaire horaire;
    Duree duree;
public:
    Evt(const Date& d=Date(0,0,0), const Horaire& h=Horaire(0,0), const Duree& du=Duree(0,0)) : date(d), horaire(h),duree(du){};
    virtual ~Evt(){};
    Date getDate()const{return date;};
    Horaire getHoraire()const{return horaire;};
    Duree getDuree()const{return duree;};
    void setDate(Date d){date = d;};
    void setHoraire(Horaire h){horaire = h;};
    void setDuree(Duree d){duree = d;};
    virtual Evt* programmer(const Date& d, const Horaire&h, const Duree& du)=0;         // Comment récupérer le pointeur vers Tache/Evt ?
};

class EvtTache : public Evt{
private:
    TUnitaire* tache;
public:
    EvtTache(const Date& da = Date(0,0,0), const Horaire& h=Horaire(0,0),const Duree& d=Duree(0), TUnitaire* t=0) : Evt(da,h,d), tache(t){
        Duree du;
        if(typeid(t).name()=="TUnitaire")
            if(t->getPreemptive()!=0)
               t->setDuree(Duree(t->getDuree().getDureeEnMinutes()-d.getDureeEnMinutes()));
    };
    EvtTache(TUnitaire* t):Evt(),tache(t){};
    TUnitaire* getTache()const{return tache;};
    EvtTache* programmer(const Date& da, const Horaire& h, const Duree& d);
};

class EvtActivite :public Evt{
private:
    Activite* activite;
public:
    EvtActivite(const Date& da=Date(0,0,0), const Horaire& h=Horaire(0,0),const Duree& d=Duree(0), Activite* a=0) : Evt(da,h,d), activite(a){}
    EvtActivite(Activite* a):Evt(),activite(a){};
    Activite* getActivite()const{return activite;};
    EvtActivite* programmer(const Date& da, const Horaire& h, const Duree& d);
};

class EvtFactory{
public:
    //Design Pattern Abstract Factory
    //On appelle newEvt avec un pointeur tache ou activité. Selon le QString passé en paramètre, on effectue un cast sur le pointeur
    static Evt* NewEvt(const QString& description, void* ptr,const Date& da, const Horaire& h,const Duree& d){     //void* ptr ?
        if(description=="tache")
            return new EvtTache(da,h,d,(TUnitaire*)ptr);
        if(description=="activite")
            return new EvtActivite(da,h,d,(Activite*)ptr);
        return NULL;
    };
};

#endif // EVENEMENT_H

