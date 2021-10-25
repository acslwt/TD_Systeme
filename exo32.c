/*fork() permet de dupliquer un processus :
    crée une ligne dans la table des processus pour le fils.
    duplique tous les élements de mémoire et ressource du père pour le fils;
     donc code,données statiques,la pile,et le tas.)

Le code de retour du fork() est le pid du fils dans le père 