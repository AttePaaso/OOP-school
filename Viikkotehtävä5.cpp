#ifndef NOTIFIKAATTORI_H
#define NOTIFIKAATTORI_H

#include <string>
#include <iostream>
using namespace std;

class Seuraaja
{
public:
    Seuraaja(string);
    Seuraaja *next = nullptr;
    string getNimi();
    void    paivitys(string);
private:
    string  nimi;
};

class Notifikaattori
{
public:
    Notifikaattori();
    void    lisaa(Seuraaja *seuraaja);
    void    poista(Seuraaja *seuraaja);
    void    tulosta();
    void    postita(string viesti);
private:
    Seuraaja *seuraajat = nullptr;
};
Seuraaja::Seuraaja(string nimi)
{
    this->nimi = nimi;
}
string  Seuraaja::getNimi()
{
    return (nimi);
}
void    Seuraaja::paivitys(string viesti)
{
    cout << nimi << " sai viestin: " << viesti << endl;
}
Notifikaattori::Notifikaattori()
{
    seuraajat = nullptr;
}
void Notifikaattori::lisaa(Seuraaja *seuraaja)
{
    seuraaja->next = seuraajat;
    seuraajat = seuraaja;
}
void    Notifikaattori::poista(Seuraaja *seuraaja)
{
    if (!seuraajat)
        return ;
    if (seuraajat == seuraaja)
    {
        seuraajat = seuraaja->next;
        return;
    }
    Seuraaja *tarkkailtava = seuraajat;
    while (tarkkailtava->next && tarkkailtava->next != seuraaja)
    {
        tarkkailtava = tarkkailtava->next;
    }
    if (tarkkailtava->next == seuraaja)
    {
        tarkkailtava->next = seuraaja->next;
    }
}
void    Notifikaattori::tulosta()
{
    Seuraaja *tarkkailtava = seuraajat;

    while (tarkkailtava)
    {
        cout << tarkkailtava->getNimi() << endl;
        tarkkailtava = tarkkailtava->next;
    }
}
void    Notifikaattori::postita(string viesti)
{
    Seuraaja *tarkkailtava = seuraajat;

    while (tarkkailtava)
    {
        tarkkailtava->paivitys(viesti);
        tarkkailtava = tarkkailtava->next;
    }
}
#endif // NOTIFIKAATTORI_H