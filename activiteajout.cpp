#include "activiteajout.h"
#include "actmanager.h"

ActiviteAjout::ActiviteAjout(QWidget *fenetre):QDialog(fenetre){
    setWindowTitle("Ajout Activité");
    setFixedSize(600,300);

    h1Layout=new QHBoxLayout;
    ltitre=new QLabel("Titre",this);
    titre=new QLineEdit(this);
    h1Layout->addWidget(ltitre);
    h1Layout->addWidget(titre);

    h2Layout=new QHBoxLayout;
    lduree=new QLabel("Duree",this);
    heure =new QSpinBox(this);
    minute =new QSpinBox(this);
    heure->setSuffix(" heures(s)");
    minute->setSuffix(" minute(s)");
    heure->setMinimum(0);
    heure->setMaximum(59);
    minute->setMinimum(0);
    minute->setMaximum(59);
    h2Layout->addWidget(lduree);
    h2Layout->addWidget(heure);
    h2Layout->addWidget(minute);

    h3Layout = new QHBoxLayout;
    annuler=new QPushButton("Annuler", this);
    ajouter = new QPushButton("Ajouter la tache", this);
    ajouter->setEnabled(false);
    h3Layout->addWidget(annuler);
    h3Layout->addWidget(ajouter);

    vLayout1 = new QVBoxLayout;
    vLayout1->addLayout(h1Layout);
    vLayout1->addLayout(h2Layout);
    vLayout1->addLayout(h3Layout);

    this->setLayout(vLayout1);
    QObject::connect(titre,SIGNAL(textChanged(QString)),this,SLOT(activerAjout()));
    QObject::connect(heure,SIGNAL(valueChanged(int)),this,SLOT(activerAjout()));
    QObject::connect(minute,SIGNAL(valueChanged(int)),this,SLOT(activerAjout()));
    QObject::connect(annuler,SIGNAL(clicked()),this,SLOT(accept()));
    QObject::connect(ajouter,SIGNAL(clicked()),this,SLOT(ajouterActivite()));
}

void ActiviteAjout::activerAjout(){
    if(titre->text()!=0 && Duree(heure->value(),minute->value()).getDureeEnMinutes()!=0)
        ajouter->setEnabled(true);      //Boutton ajouter
    if(titre->text()==0)
        ajouter->setEnabled(false);
}

void ActiviteAjout::ajouterActivite(){
    ActiviteManager& am = ActiviteManager::getInstance();
    am.ajouterAct(titre->text(),Duree(heure->value(),minute->value()));
    this->accept();
}
