#include "progManager.h"

//Méthodes de progManager
   void ProgManager::ajouterProg(const Date& d, const Horaire& h){		//A vérifier
   		if(nb==nbMax){
   			nbMax +=10;
   			Prog** tmp = new Prog*[nbMax];
   			for(int i=0;i<nb;i++)
   				tmp[i] = prog[i];
   			Prog** old = prog;
   			prog = tmp;
   			delete[] old;
   		}
   		prog[nb++]=Prog(d,h);
   }		

   // Prog* ProgManager::trouverProg();	En a-t-on besoin ? 
    ProgManager& getInstance(){
    	if(handler.instance==0)
    		handler.instance = new ProgManager;
    	return *handler.instance;
    }

    void ProgManager::freeInstance(){
    	if(handler.instance!=0)
    		delete handler.instance;
    	handler.instance=0;
    }

    IteratorSTL ProgManager::IteratorSTL::begin()const{
    	return IteratorSTL(prog);
    }

    IteratorSTL ProgManager::IteratorSTL::end()const{
    	return IteratorSTL(prog+nb);
    }