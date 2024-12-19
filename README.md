# TP Synthèse 2 - Client TFTP 
**BOUTONNET Léo  AMINE Osmane**

## Réalisation de gettftp :
Dans un premier temps, nous récuperons les informations sur le serveur hôte grâce aux paramètres fournis dans la requête de gettftp :  

    $ gettftp 127.0.0.1 1069 zeros256

On récupère donc le nom du serveur, le port utilisé, et le nom du fichier :  

    char* host_adrr=argv[1];
    char* host_port=argv[2]; 
    char* filename=argv[3];

On obtient ensuite ses coordonnées avec `getaddrinfo` :  

    getaddrinfo(host_adrr, host_port, &hints, &res);

Le resultat est stocké dans res, et hints permet de filtrer la recherche d'addresse internet selon le protocole UDP :  

    struct addrinfo hints;
    memset(&hints, 0, sizeof(struct addrinfo));
    (&hints)->ai_protocol=IPPROTO_UDP;
    (&hints)->ai_family=AF_INET;
    (&hints)->ai_socktype=SOCK_DGRAM;

On procède ensuite à la réservation du socket.


