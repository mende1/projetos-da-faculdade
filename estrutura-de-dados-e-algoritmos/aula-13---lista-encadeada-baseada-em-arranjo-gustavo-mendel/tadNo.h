/* Classe data */ 

#include<iostream>

class cNo {
  private: 
    int dado;
    int prox;

  public:
  	cNo();
  	cNo(int dado);
  	cNo(const cNo &n);
  	~cNo();

  	void setDado(int d);
  	void setProx(int p);
  	int  getDado();
  	int  getProx();

};

