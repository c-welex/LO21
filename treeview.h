#ifndef TREEVIEW_H
#define TREEVIEW_H
#include<QtWidgets>
#include"projetmanager.h"
#include"projetManager.h"
class Projet;
class Tache;
>>>>>>> en_dev
class treeView: public QDialog
{
    Q_OBJECT
private:
    QTreeWidget* tree;
    QPushButton* retour;
public:
    treeView(QWidget* fenetre);
    void AjouterArbre(QTreeWidget *t);
    void AjouterArbre(QTreeWidget *t, Projet& p);
    void AjouterArbre(QTreeWidgetItem *t,const Tache& tc);
};

#endif // TREEVIEW_H
