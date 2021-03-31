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

PutVoxel::PutVoxel(int x, int y, int z, float r, float g, float b, float a){
  this->x=x; this->y=y; this->z=z;
  this->r=r; this->g=g; this->b=b; this->a=a;
}

void PutVoxel::draw(Sculptor &s){
  s.setColor(r,g,b,a);
  s.putVocel(x,y,z);
}

class FiguraGeometrica{
  protected:
    float r,g,b,a;
  public:
    virtual ~FiguraGeometrica(){};
    virtual void draw(Sculptor &s)=0;
};

//estrutura para os blocos.
struct Voxel {
  float r; // Quantidade de Vermelho
  float g; // Quantidade de Verde
  float b; // Quantidade de Azul
  float a; // Transparência
  bool isOn; // Variável para ativar ou não o voxel
};

//classe para moldar o objeto.
class Sculptor {
protected:
  Voxel ***v; // Matrix 3D 
  int nx,ny,nz; // Dimensões
  float r,g,b,a; // Cor e transparência atuais do desenho
public:
  //Alocação da Matriz 3D.
    /**
    * @brief Função para alocar a matriz necessária para esculpir os desenhos.
    */
  Sculptor(int _nx, int _ny, int _nz);

  //Liberação de memória
    /**
    * @brief Função para liberar a memória ocupada pela matriz necessária para esculpir os desenhos.
    */
  ~Sculptor();

  /**
    * @brief Atribuição das cores do objeto que está sendo desenvolvido.
    * @param red, green, blue são os parâmetros para definir a quantidade de vermelho, verde e azul, respectivamente, do que será
    * desenhado. O usuário pode digitar um número float no intervalo de zero a um, representando, nessa ordem, a ausência
    * completa da cor e a presença máxima dela cor.
    * @param alpha define a transparência do objeto, variando também de zero à um, conforme descrito acima.
    */
  void setColor(float red, float green, float blue, float alpha);

  /**
   * @brief Adiciona um Voxel dentro da matriz
   * @param x,y,z representam as cordenadas espaciais de onde você deseja inserir esse voxel.
   */
  void putVoxel(int x, int y, int z);

  /**
     * @brief Essa função tem por finalidade desconstruir um voxel já inserido dentro da matriz.
     * @param x,y,z são as coordenadas espaciais do voxel que se quer desconstruir
       */
  void cutVoxel(int x, int y, int z);

  /**
      * @brief Cria uma sequência de Voxels em forma de um cubo.
      * @param x0,y0,z0 são as coordenadas iniciais de onde será construído.
      * @param x1,y1,z1 delimitam as coordenadas nas quais o cubo será construído
      */
  void putBox(int x0, int x1, int y0, int y1, int z0, int z1);

  /**
      * @brief Corta uma sequência de Voxels em forma de cubo.
      * @param Os parâmetros possuem o mesmo significado dos encontrados na função putBox, mas dessa vez para desconstruir.
      */
  void cutBox(int x0, int x1, int y0, int y1, int z0, int z1);

  /**
      * @brief Cria uma sequência de Voxels em forma de esfera.
      * @param xcenter é o centro da esfera na coordenada x;
      * @param ycenter é o centro da esfera na coordenada y;
      * @param zcenter é o centro da esfera na coordenada z;
      * @param radius é o raio da esfera.
      */
  void putSphere(int xcenter, int ycenter, int zcenter, int radius);

  /**
      * @brief Corta uma sequência de Voxels em forma de esfera.
      * @param são os mesmos da função putSphere
      */
  void cutSphere(int xcenter, int ycenter, int zcenter, int radius);

  /**
      * @brief Cria uma sequência de Voxels em forma de elipsóide.
      * @param xcenter,ycenter,zcenter representam o centro da elipsóide nas componentes x, y e z da matriz
      * @param rx,ry,rz representam o raio do elipsóide nas componentes x, y e z da matriz
      */
  void putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);

  /**
      @brief Corta uma sequência de Voxels, Em forma de elipsóide.
      @param são os mesmo da função putEllipsoid
        */
  void cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);

   /**
      @brief Cria um arquivo para leitura do desenho, contendo suas dimensões e cores.
      */
  void writeOFF(char* filename);
};
#endif // SCULPTOR_H


