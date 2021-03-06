#ifndef SCULPTOR_H
#define SCULPTOR_H

#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <iomanip> 

using namespace std;

class PutVoxel : public FiguraGeometrica {
  int x, y, z;
public: 
  PutVoxel(int x, int y, int z, float r, float g, float b, float a);
  ~PutVoxel(){}
  void draw(Sculptor &s);
};

class FiguraGeometrica{
  protected:
    float r,g,b,a;
  public:
    virtual ~FiguraGeometrica(){};
    virtual void draw(Sculptor &s)=0;
};

PutVoxel::PutVoxel(int x, int y, int z, float r, float g, float b, float a){
  this->x=x; this->y=y; this->z=z;
  this->r=r; this->g=g; this->b=b; this->a=a;
}

void PutVoxel::draw(Sculptor &s){
  s.setColor(r,g,b,a);
  s.putVoxel(x,y,z);
}

PutSphere::PutSphere(int xc, int yc, int zc, int radius, float r, float g, float b, float a){
  this->xc = xc; this ->yc = yc; this-> zc = zc; this->radius = radius; this->r = r; this -> g;
  this->b = b; this->a =a;
}

void PutSphere::draw(Sculptor &s){
  double calc;
  int x, y, z;
  calc = radius*radius;
  s.setColor(r,g,b,a);
  for(x=xc-radius; x<xc+radius; x++){
    for(y=yc-radius; y<yc+radius; y++){
      for(z=zc-radius; z<zc+radius; z++){
        if(static_cast<double>(x-xc)*static_cast<double>(x-xc)+
           static_cast<double>(y-yc)*static_cast<double>(y-yc)+
           static_cast<double>(z-zc)*static_cast<double>(z-zc) < calc
           ) 
        {
             s.putVoxel(x,y,z);
        }
      }
    }
  }
}

PutBox::~PutBox(){
  std::cout << "destuctor PutBox\n";
}

void PutBox::draw(Sculptor &s) {
  int x, y, z;
  s.setColor(r,g,b,a);
  if (x0 > x1)
  {
    troca(x0, x1);
  }
  if (y0 > y1)
  {
    troca(y0, y1);
  }
  if (z0 > z1)
  {
    troca(z0, z1);
  }
  if(x0 < 0) {
    x0 = 0;
  }
  for (x=x0; x<=x1;x++){
    for (y=y0; y<=y1;y++){
      for (z=z0; z<=z1;z++){
        s.putVoxel(x,y,z);
      }
    }
  }
  
}

Interpretador::Interpretador(){

}

std::vector<FiguraGeometrica*> Interpretador::parse(std::string filename) {
  std::vector<FiguraGeometrica*> figs;
  std::ifstream fin;
  std::stringstream ss;
  std::string s, token;

  fin.open(filename.c_str());
  if(!fin.is_open()){
    std::cout << "o fluxo nao abriu ????" << filename << std::endl;
    exit(0);
  }

  while (fin.good())
  {
    std::getline(fin, s);
    if(fin.good()){
      ss.clear();
      ss.str(s);
      ss >> token;
      if(ss.good()){
        if(token.compare("dim") == 0){
          ss >> dimx >> dimy >> dimz;
        }

        else if(token.compare("putvoxel") == 0){
          int x0, y0, z0;
          ss >> x0 >> y0 >> z0 >> r >> g >> b >> a;
          figs.push_back(new PutVoxel(x0, y0, z0, r, g, b, a));
        }
        else if(token.compare("putsphere") == 0){
          int x0, y0, z0, rr;
          ss >> x0 >> y0 >> z0 >> rr >> r >> g >> b >> a;
          figs.push_back(new PutVoxel(x0, y0, z0, rr, r, g, b, a));
        }
      }
    }
  }
  return(figs);
}

int Interpretador::getDimx(){
  return dimx;
}

int Interpretador::getDimy(){
  return dimy;
}

int Interpretador::getDimz(){
  return dimz;
}

//estrutura para os blocos.
struct Voxel {
  float r; // Quantidade de Vermelho
  float g; // Quantidade de Verde
  float b; // Quantidade de Azul
  float a; // Transpar??ncia
  bool isOn; // Vari??vel para ativar ou n??o o voxel
};

//classe para moldar o objeto.
class Sculptor {
protected:
  Voxel ***v; // Matrix 3D 
  int nx,ny,nz; // Dimens??es
  float r,g,b,a; // Cor e transpar??ncia atuais do desenho
public:
  //Aloca????o da Matriz 3D.
    /**
    * @brief Fun????o para alocar a matriz necess??ria para esculpir os desenhos.
    */
  Sculptor(int _nx, int _ny, int _nz);

  //Libera????o de mem??ria
    /**
    * @brief Fun????o para liberar a mem??ria ocupada pela matriz necess??ria para esculpir os desenhos.
    */
  ~Sculptor();

  /**
    * @brief Atribui????o das cores do objeto que est?? sendo desenvolvido.
    * @param red, green, blue s??o os par??metros para definir a quantidade de vermelho, verde e azul, respectivamente, do que ser??
    * desenhado. O usu??rio pode digitar um n??mero float no intervalo de zero a um, representando, nessa ordem, a aus??ncia
    * completa da cor e a presen??a m??xima dela cor.
    * @param alpha define a transpar??ncia do objeto, variando tamb??m de zero ?? um, conforme descrito acima.
    */
  void setColor(float red, float green, float blue, float alpha);

  /**
   * @brief Adiciona um Voxel dentro da matriz
   * @param x,y,z representam as cordenadas espaciais de onde voc?? deseja inserir esse voxel.
   */
  void putVoxel(int x, int y, int z);

  /**
     * @brief Essa fun????o tem por finalidade desconstruir um voxel j?? inserido dentro da matriz.
     * @param x,y,z s??o as coordenadas espaciais do voxel que se quer desconstruir
       */
  void cutVoxel(int x, int y, int z);

  /**
      * @brief Cria uma sequ??ncia de Voxels em forma de um cubo.
      * @param x0,y0,z0 s??o as coordenadas iniciais de onde ser?? constru??do.
      * @param x1,y1,z1 delimitam as coordenadas nas quais o cubo ser?? constru??do
      */
  void putBox(int x0, int x1, int y0, int y1, int z0, int z1);

  /**
      * @brief Corta uma sequ??ncia de Voxels em forma de cubo.
      * @param Os par??metros possuem o mesmo significado dos encontrados na fun????o putBox, mas dessa vez para desconstruir.
      */
  void cutBox(int x0, int x1, int y0, int y1, int z0, int z1);

  /**
      * @brief Cria uma sequ??ncia de Voxels em forma de esfera.
      * @param xcenter ?? o centro da esfera na coordenada x;
      * @param ycenter ?? o centro da esfera na coordenada y;
      * @param zcenter ?? o centro da esfera na coordenada z;
      * @param radius ?? o raio da esfera.
      */
  void putSphere(int xcenter, int ycenter, int zcenter, int radius);

  /**
      * @brief Corta uma sequ??ncia de Voxels em forma de esfera.
      * @param s??o os mesmos da fun????o putSphere
      */
  void cutSphere(int xcenter, int ycenter, int zcenter, int radius);

  /**
      * @brief Cria uma sequ??ncia de Voxels em forma de elips??ide.
      * @param xcenter,ycenter,zcenter representam o centro da elips??ide nas componentes x, y e z da matriz
      * @param rx,ry,rz representam o raio do elips??ide nas componentes x, y e z da matriz
      */
  void putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);

  /**
      @brief Corta uma sequ??ncia de Voxels, Em forma de elips??ide.
      @param s??o os mesmo da fun????o putEllipsoid
        */
  void cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);

   /**
      @brief Cria um arquivo para leitura do desenho, contendo suas dimens??es e cores.
      */
  void writeOFF(char* filename);
};
#endif // SCULPTOR_H


