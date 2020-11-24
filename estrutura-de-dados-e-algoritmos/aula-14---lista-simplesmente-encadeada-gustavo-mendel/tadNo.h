/* Classe data */ 

#include<iostream>

class cNo {
  private: 
    int dado;
    cNo* prox;

  public:
  	cNo();
  	cNo(int dado);
  	cNo(const cNo &n);
  	~cNo();

  	void setDado(int d);
  	void setProx(cNo* p);
  	int  getDado();
  	cNo* getProx();

	friend std::ostream &operator<<( std::ostream &output, const cNo &n);

};

