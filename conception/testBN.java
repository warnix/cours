void TestCaseBN(){
    CaseBN case = new CaseBN(0,0,true);
    EtatCaseBN etat = "NON_DECOUVERTE";
    getEtatCaseTest(case,etat);
    EtatCaseBN etat2 = "BATEAU_TOUCHE";
    torpillerCaseTest(case,etat2);
    CaseBN case2 = new CaseBN(0,0,false);
    EtatCaseBN etat3 = "A_L_EAU";
    getEtatCaseTest(case,etat3)
    torpillerCaseTest(case,etat3);    
}


void TestJoueurBN(){
    Collection<CaseBN> collection1 = new Collection<CaseBN>();
    Collection<CaseBN> collection2 = new Collection<CaseBN>();
    CaseBN case1 = new CaseBN(0,0,true);
    collection1.add(case1);
    collection1.add(case2);
    CaseBN case3 = new CaseBN(0,0,false);
    CaseBN case4 = new CaseBN(1,1,true);
    collection2.add(case3);
    collection2.add(case4);
    JoueurBN joueur= new JoueurBN(j1,1,collection1);
    JoueurBN joueur= new JoueurBN(j2,2,collection2);
    EtatJeu etatJeu1 = "enCours";
    EtatJeu etatJeu2 = "TERMINE";
    //1er torpille j2 sur une case sans bateau, pas de touche, partie en cours
    torpillerTest(j2,etatJeu1,O,1, collection2.get(0));
    //2eme torpille j2 sur une case avec bateau, touche, fin de partie
    torpillerTest(j2,etatJeu2,1,2, collection2.get(1));
    //1er torpille j1 sur une case avec bateua, touche, fin partie
    torpillerTest(j1,etatJeu2,1,1);
}

void torpillerTest(JoueurBN j, EtatJeu etatJeuAttendue, 
CaseBN case, int nbToucheAttendue, int nbTirsAttendue){
    EtatJeu retourEtatJeu = j.torpiller(case.getX,case.getY);
    assert(etatJeuAttendue, retourEtatJeu);
    assert(nbToucheAttendue,j.getNombreTouchesRecues());
    assert(nbTirsAttendue,j.getNombreTirsRecues());
    assert(true,case.getTorpiller());
}

void testControlleurBN(){
    Collection<CaseBN> collection1 = new Collection<CaseBN>();
    Collection<CaseBN> collection2 = new Collection<CaseBN>();
    CaseBN case1 = new CaseBN(0,0,true);
    CaseBN case2 = new CaseBN(1,1,true);
    collection1.add(case1);
    collection1.add(case2);
    CaseBN case3 = new CaseBN(0,0,false);
    CaseBN case4 = new CaseBN(1,1,true);
    collection2.add(case3);
    collection2.add(case4);
    JoueurBN j1= new JoueurBN(j1,1,collection1);
    JoueurBN j2= new JoueurBN(j2,2,collection2);
    ControleurBN controleur= new controleur(j1,j2,1,2);
    //1er tir j1, torpille sur une case sans bateau, pas de touche, partie en cours
    tirParJoueurTest(0,0,1, controleur, false, false)
    //1er tir j2, torpille sur une case avec bateau, touche, partie en cours
    tirParJoueurTest(1,1,2, controleur, false,false);
    //2eme tir j1, torpille sur une case avec bateau, touche, fin de partie
    tirParJoueurTest(1,1,1, controleur, false, true);
    //2eme tir j2, torpille sur une case, partie déjà terminé
    tirParJoueurTest(0,0,2,controleur,true,false);
}
void tirParJoueurTest(int x, int y, int j, ControlleurBN controleur,
 boolean estTerminé, boolean gagnant){
    int j2;
    if(estTerminé){
        assert(false, controleur.tirParJoueur(x,y,j));
    }else{
        if(x<0 || y<0 
        || x>1+controleur.getTailleEchequier() || y>1+controleur.getTailleEchequier()){
            assert(false, controleur.tirParJoueur(x,y,j));
        }else{
            if(j==1){
                assert(false, controleur.tirParJoueur(0,0,2));
                j2 = 2;
            }else{
                assert(false, controleur.tirParJoueur(0,0,1));
                j2 = 1;
            }
            assert(true, controleur.tirParJoueur(x,y,j));
            if(gagnant){
                assert(j,controleur.getGagnant());
            }else{
                assert(j2,controleur.getJoueurCourant());
            }
        }
    }
}
