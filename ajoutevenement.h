#ifndef AJOUTEVENEMENT_H
#define AJOUTEVENEMENT_H
#include<QtWidgets>
#include"evtManager.h"
#include "projetManager.h"
#include "actmanager.h"

class ajoutEvenement:public QDialog
{
    Q_OBJECT
private:
    QHBoxLayout* classlayout, *listelayout,*timelayout,*dureelayout,*boutonlayout;
    QButtonGroup* evtclasse;
    QRadioButton *tacheevt, *activiteevt;
    QVBoxLayout *vLayout;
    QLabel *lliste, *lduree, *lhoraire, *ldate, *lpro;
    QComboBox* listeEle,*listePro;
    QSpinBox* hHoraire;
    QSpinBox* mHoraire, *mDuree;
    QDateEdit* date;
    QPushButton* annuler, *ajouter;

public:
    ajoutEvenement(QWidget* fenetre);
    void afficheTacheU();
    void afficheActivite();
    void afficheSousTacheU(const TComposite& t);
    void contrainteTache(QString s);
    void contrainteActivite();

/*private slots:
    void activerAjout();*/

public slots:
    void modifierSelection(bool b);
    void modifierContrainte(QString s);
    void modifierTache(int s);
    void ajouterEvenement();

};


#endif // AJOUTEVENEMENT_H
