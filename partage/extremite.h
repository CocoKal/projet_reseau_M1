#ifndef EXTREMITE_H
#define EXTREMITE_H


/**
 * Lit un paquet sur le fd socket et l'écrit dans le fd tun
 * @param socket
 * @param tun
 * @return -1 si erreur
 */
int socket_to_tun(int socket, int tun);


/**
 * Créer un serveur qui redirige les paquets entrant vers un descripteur de fichier
 * @param port port d'écoute du serveur
 * @param fd descripteur de fichier où va être redirigé la donnée
 * @return
 */
int ext_out (char* port, int fd);

/**
 * Envoie des sockets au serveur depuis tun0
 * @param ipServ ip du serveur
 * @param port du serveur
 * @param fdtun Description du fichier du tunnel
 * @return
 */
int ext_in(char* ipServ, char* port, int fdTun);

#endif
