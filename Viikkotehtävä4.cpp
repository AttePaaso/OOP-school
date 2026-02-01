#ifndef PANKKITILIT_H
#define PANKKITILIT_H

#include <string>
using namespace std;

class Pankkitili
{
    public:
        Pankkitili(string);
        double  getBalance();
        {
            return (saldo);
        }
        bool    deposit(double amount)
        {
            if (amount < 0)
                return (1);
            saldo += amount;
            return (0);
        }
        bool    withdraw(double amount)
        {
            if (saldo < amount || amount < 0)
                return (1);
            saldo -= amount;
            return (0);
        }
    protected:
        string omistaja;
        double  saldo = 0;
};
class   Luottotili : public Pankkitili
{
    public:
        Luottotili(string,double);
        bool    deposit(double amount)
        {
            if (amount < 0)
                return (1);
            saldo += amount;
            return (0);
        }
        bool    withdraw(double amount)
        {
            if (amount < 0 || amount > saldo + luottoraja)
                return (1);
            saldo -= amount;
            return (0);
        }
    private:
        double Luottoraja = 0;
};
class Asiakas
{
    public:
        Asiakas(string, double);
        string  getNimi(void);
        void    showSaldo(void);
        {
            cout << Pankkitili.getBalance();
            cout << Luottotili.getBalance();
        }
        bool    talletus(double amount)
        {
            return(Pankkitili.deposit(amount));
        }
        bool    nosto(double amount)
        {
            return(Pankkitili.withdraw(amount));
        }
        bool    luotonMaksu(double amount)
        {
            return(Luottotili.deposit(amount));
        }
        bool    luotonNosto(double amount)
        {
            return(Luottotili.withdraw(amount));
        }
    private:
        string  nimi;
        Pankkitili  käyttötili;
        Luottotili  luottotili;
};