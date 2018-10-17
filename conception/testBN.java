void TestBN(){
    CaseBN case = new CaseBN(0,0,true);
    EtatCaseBN etat = "NON_DECOUVERTE";
    getEtatTest(case,etat);
    EtatCaseBN etat2 = "BATEAU_TOUCHE";
    torpillerTest(case,etat2);
    CaseBN case2 = new CaseBN(0,0,false);
    EtatCaseBN etat3 = "A_L_EAU";
    getEtatTest(case,etat3)
    torpillerTest(case,etat3);
}
