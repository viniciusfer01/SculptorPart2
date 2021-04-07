#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip> 
#include "sculptor.h"

// struct Voxel {
//   float r; // Quantidade de Vermelho
//   float g; // Quantidade de Verde
//   float b; // Quantidade de Azul
//   float a; // Transparência
//   bool isOn; // Variável para ativar ou não o voxel
// };

// //classe para moldar o objeto.
// class Sculptor {
// protected:
//   Voxel ***v; // Matrix 3D 
//   int nx,ny,nz; // Dimensões
//   float r,g,b,a; // Cor e transparência atuais do desenho
// public:
//   //Alocação da Matriz 3D.
//     /**
//     * @brief Função para alocar a matriz necessária para esculpir os desenhos.
//     */
//   Sculptor(int _nx, int _ny, int _nz);

//   //Liberação de memória
//     /**
//     * @brief Função para liberar a memória ocupada pela matriz necessária para esculpir os desenhos.
//     */
//   ~Sculptor();

//   /**
//     * @brief Atribuição das cores do objeto que está sendo desenvolvido.
//     * @param red, green, blue são os parâmetros para definir a quantidade de vermelho, verde e azul, respectivamente, do que será
//     * desenhado. O usuário pode digitar um número float no intervalo de zero a um, representando, nessa ordem, a ausência
//     * completa da cor e a presença máxima dela cor.
//     * @param alpha define a transparência do objeto, variando também de zero à um, conforme descrito acima.
//     */
//   void setColor(float red, float green, float blue, float alpha);

//   /**
//    * @brief Adiciona um Voxel dentro da matriz
//    * @param x,y,z representam as cordenadas espaciais de onde você deseja inserir esse voxel.
//    */
//   void putVoxel(int x, int y, int z);

//   /**
//      * @brief Essa função tem por finalidade desconstruir um voxel já inserido dentro da matriz.
//      * @param x,y,z são as coordenadas espaciais do voxel que se quer desconstruir
//        */
//   void cutVoxel(int x, int y, int z);

//   /**
//       * @brief Cria uma sequência de Voxels em forma de um cubo.
//       * @param x0,y0,z0 são as coordenadas iniciais de onde será construído.
//       * @param x1,y1,z1 delimitam as coordenadas nas quais o cubo será construído
//       */
//   void putBox(int x0, int x1, int y0, int y1, int z0, int z1);

//   /**
//       * @brief Corta uma sequência de Voxels em forma de cubo.
//       * @param Os parâmetros possuem o mesmo significado dos encontrados na função putBox, mas dessa vez para desconstruir.
//       */
//   void cutBox(int x0, int x1, int y0, int y1, int z0, int z1);

//   /**
//       * @brief Cria uma sequência de Voxels em forma de esfera.
//       * @param xcenter é o centro da esfera na coordenada x;
//       * @param ycenter é o centro da esfera na coordenada y;
//       * @param zcenter é o centro da esfera na coordenada z;
//       * @param radius é o raio da esfera.
//       */
//   void putSphere(int xcenter, int ycenter, int zcenter, int radius);

//   /**
//       * @brief Corta uma sequência de Voxels em forma de esfera.
//       * @param são os mesmos da função putSphere
//       */
//   void cutSphere(int xcenter, int ycenter, int zcenter, int radius);

//   /**
//       * @brief Cria uma sequência de Voxels em forma de elipsóide.
//       * @param xcenter,ycenter,zcenter representam o centro da elipsóide nas componentes x, y e z da matriz
//       * @param rx,ry,rz representam o raio do elipsóide nas componentes x, y e z da matriz
//       */
//   void putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);

//   /**
//       @brief Corta uma sequência de Voxels, Em forma de elipsóide.
//       @param são os mesmo da função putEllipsoid
//         */
//   void cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);

//    /**
//       @brief Cria um arquivo para leitura do desenho, contendo suas dimensões e cores.
//       */
//   void writeOFF(char* filename);
// };

int main() {
    Sculptor *s1;
    Sculptor s(50,50,50);

    Interpretador parser;

    std::vector<FiguraGeometrica*> figs;

    figs = parser.parse("escultura.txt");

    s1 = new Sculptor(parser.getDimx(), parser.getDimy(), parser.getDimz());

    for (int i = 0; i < figs.size(); i++)
    {
      std::cout << "draw\n";
      figs[i]->draw(*s1);
    }

    //s1 -> limpaVoxels();

    s1 -> writeOFF((char*)"/saida.off");
    for (int i = 0; i < figs.size(); i++) {
      delete figs[i];
    }

    delete s1;
    

    


    
    // Sculptor Voxel(50,50,50);
    // Voxel.setColor(0.00,0.00,0.93,1);
    // Voxel.putEllipsoid(15,15,17,3,3,12); //corpo do foguete
    // Voxel.cutBox(0,29,0,29,0,7);
    
    // Voxel.setColor(1.00,0.00,0.0,1); //fogo do foguete
    // Voxel.putEllipsoid(15,15,15,2,2,12); 

    // Voxel.setColor(1.00,1.00,0.00,1); //aleta do foguete
    
    // for (int i = 16; i > 8; i--)
    // {
    //   Voxel.putVoxel(12, 15, i);
    // }

    // for (int i = 15; i > 7; i--)
    // {
    //   Voxel.putVoxel(11, 15, i);
    // }

    // for (int i = 14; i > 6; i--)
    // {
    //   Voxel.putVoxel(10, 15, i);
    // }

    // for (int i = 13; i > 5; i--)
    // {
    //   Voxel.putVoxel(9, 15, i);
    // }
    


    // for (int i = 16; i > 8; i--)
    // {
    //   Voxel.putVoxel(18, 15, i);
    // }

    // for (int i = 15; i > 7; i--)
    // {
    //   Voxel.putVoxel(19, 15, i);
    // }

    // for (int i = 14; i > 6; i--)
    // {
    //   Voxel.putVoxel(20, 15, i);
    // }

    // for (int i = 13; i > 5; i--)
    // {
    //   Voxel.putVoxel(21, 15, i);
    // }



    // for (int i = 16; i > 8; i--)
    // {
    //   Voxel.putVoxel(15, 12, i);
    // }

    // for (int i = 15; i > 7; i--)
    // {
    //   Voxel.putVoxel(15, 11, i);
    // }

    // for (int i = 14; i > 6; i--)
    // {
    //   Voxel.putVoxel(15, 10, i);
    // }

    // for (int i = 13; i > 5; i--)
    // {
    //   Voxel.putVoxel(15, 9, i);
    // }
    


    // for (int i = 16; i > 8; i--)
    // {
    //   Voxel.putVoxel(15, 18, i);
    // }

    // for (int i = 15; i > 7; i--)
    // {
    //   Voxel.putVoxel(15, 19, i);
    // }

    // for (int i = 14; i > 6; i--)
    // {
    //   Voxel.putVoxel(15, 20, i);
    // }

    // for (int i = 13; i > 5; i--)
    // {
    //   Voxel.putVoxel(15, 21, i);
    // } 

    // Voxel.setColor(0.36,0.74,0.93,0.5); //janela
    // Voxel.putVoxel(12, 15, 24); 
    // Voxel.setColor(0.40,0.40,0.40,1);
    // Voxel.putVoxel(12, 14, 24); 
    // Voxel.putVoxel(12, 16, 24); 
    // Voxel.putVoxel(12, 15, 25); 
    // Voxel.putVoxel(12, 15, 23); 
    // Voxel.setColor(0.20,0.20,0.20,1);
    // Voxel.putVoxel(13, 14, 25); 
    // Voxel.putVoxel(13, 16, 25); 
    // Voxel.putVoxel(13, 14, 23); 
    // Voxel.putVoxel(13, 16, 23); 
    // Voxel.putVoxel(13, 14, 24); 
    // Voxel.putVoxel(13, 16, 24); 
    // Voxel.putVoxel(13, 15, 25); 
    
    // Voxel.setColor(1,1,1,1); // estrelas
    // int i = 0;
    // while (i < 75)
    // {
    //   int v1 = rand() % 50; 
    //   int v2 = rand() % 50;         
    //   int v3 = rand() % 50;
    //   if ((v1 > 19 || v1 < 11))
    //   {            
    //     Voxel.putVoxel(v1, v2, v3);
    //     i++;
    //   }
    //   else if ((v2 > 19 || v2 < 11))
    //   {            
    //     Voxel.putVoxel(v1, v2, v3);
    //     i++;
    //   }
    // }    

    // Voxel.putSphere(75,75,75,25);
    
    // Voxel.writeOFF((char*)"fogueteComLua.off");

    return 0;
}

Sculptor::Sculptor(int _nx, int _ny, int _nz) {
  nx = _nx; ny = _ny; nz = _nz;
  r=g=b=a=0.5;

  v = new Voxel**[nx];

  for (int i = 0; i < nx; i++) {
    v[i] = new Voxel*[ny];
  }

  for (int i = 0; i < nx; i++) {
    for (int j = 0; j < ny; j++) {
      v[i][j] = new Voxel[nz];
    }
  } 

  for (int i = 0; i < nx; i++) {
      for (int j = 0; j < ny; j++) {
          for (int k = 0; k < nz; k++) {
              v[i][j][k].r = r;
              v[i][j][k].g = g; 
              v[i][j][k].b = b; 
              v[i][j][k].a = a; 
              v[i][j][k].isOn = false;
          }
      }
  }   
}

Sculptor::~Sculptor() {
  //deallocate memory
  for (int i = 0; i < nx; i++)
    {
      for (int j = 0; j < ny; j++)
      {
        delete[] v[i][j];
      }
      delete[] v[i];
    }
    delete[] v;
}

void Sculptor::setColor(float red, float green, float blue, float alpha) {
  r = red; g = green; b = blue; a = alpha;
}

void Sculptor::cutVoxel(int x, int y, int z) {
  v[x][y][z].isOn = false;
} 

void Sculptor::putVoxel(int x, int y, int z){
  v[x][y][z].isOn = true;
  v[x][y][z].r = r;
  v[x][y][z].g = g;
  v[x][y][z].b = b;
  v[x][y][z].a = a;

}

void Sculptor::writeOFF(char* filename){
  int total, index, x, y, z;
  float lado = 0.5;
  ofstream f;
  total = 0;
  f.open(filename);
  f << "OFF\n";

  for (x = 0; x < nx; x++)
  {
    for (y = 0; y < ny; y++)
    {
      for (z = 0; z < nz; z++)
      {
        if (v[x][y][z].isOn) {
          total++;
        }
      }
      
    }
    
  }

  f << total * 8 << " " << total * 6 << " 0 \n";

  for (x = 0; x < nx; x++)
  {
    for (y = 0; y < ny; y++)
    {
      for (z = 0; z < nz; z++)
      {
        if (v[x][y][z].isOn) {
          f << x - lado << " " << y + lado << " " << z - lado << "\n" << flush;
          f << x - lado << " " << y - lado << " " << z - lado << "\n" << flush;
          f << x + lado << " " << y - lado << " " << z - lado << "\n" << flush;
          f << x + lado << " " << y + lado << " " << z - lado << "\n" << flush;
          f << x - lado << " " << y + lado << " " << z + lado << "\n" << flush;
          f << x - lado << " " << y - lado << " " << z + lado << "\n" << flush;
          f << x + lado << " " << y - lado << " " << z + lado << "\n" << flush;
          f << x + lado << " " << y + lado << " " << z + lado << "\n" << flush;
  
        }
      }
    }
      
  }

  total = 0;  
  for (x = 0; x < nx; x++)
  {
    for (y = 0; y < ny; y++)
    {
      for (z = 0; z < nz; z++)
      {
        if (v[x][y][z].isOn) {
          index = total * 8;

          f << std::fixed;
          f << 4 << " " << index + 0 << " " << index + 3 << " " << index + 2 << " " 
            << index + 1 << " ";
          f << std::setprecision(2) << v[x][y][z].r << " "
            << std::setprecision(2) << v[x][y][z].g << " "
            << std::setprecision(2) << v[x][y][z].b << " "
            << std::setprecision(2) << v[x][y][z].a << "\n";

          f << 4 << " " << index + 4 << " " << index + 5 << " " << index + 6 << " " 
            << index + 7 << " ";
          f << std::setprecision(2) << v[x][y][z].r << " "
            << std::setprecision(2) << v[x][y][z].g << " "
            << std::setprecision(2) << v[x][y][z].b << " "
            << std::setprecision(2) << v[x][y][z].a << "\n";

          f << 4 << " " << index + 0 << " " << index + 1 << " " << index + 5 << " " 
            << index + 4 << " ";
          f << std::setprecision(2) << v[x][y][z].r << " "
            << std::setprecision(2) << v[x][y][z].g << " "
            << std::setprecision(2) << v[x][y][z].b << " "
            << std::setprecision(2) << v[x][y][z].a << "\n";
          
          f << 4 << " " << index + 0 << " " << index + 4 << " " << index + 7 << " " 
            << index + 3 << " ";
          f << std::setprecision(2) << v[x][y][z].r << " "
            << std::setprecision(2) << v[x][y][z].g << " "
            << std::setprecision(2) << v[x][y][z].b << " "
            << std::setprecision(2) << v[x][y][z].a << "\n";

          f << 4 << " " << index + 3 << " " << index + 7 << " " << index + 6 << " " 
            << index + 2 << " ";
          f << std::setprecision(2) << v[x][y][z].r << " "
            << std::setprecision(2) << v[x][y][z].g << " "
            << std::setprecision(2) << v[x][y][z].b << " "
            << std::setprecision(2) << v[x][y][z].a << "\n";

          f << 4 << " " << index + 1 << " " << index + 2 << " " << index + 6 << " " 
            << index + 5 << " ";
          f << std::setprecision(2) << v[x][y][z].r << " "
            << std::setprecision(2) << v[x][y][z].g << " "
            << std::setprecision(2) << v[x][y][z].b << " "
            << std::setprecision(2) << v[x][y][z].a << "\n";

          total++;
        }
      } 
    } 
  }
  f.close();
} 

void Sculptor::putBox(int x0, int y0, int z0, int x1, int y1, int z1){
    //Verificação das dimensões atribuida.
    if(x0<0 || x0>nx || y0<0 || y0>ny || z0<0 || z0>nz || x1<0 || x1>nx || y1<0 || y1>ny || z1<0 || z1>nz){
        cout <<"Dimensoes erradas, digite novamente"<<endl;
        exit(1);
    }
    else{
        //Análisando os Voxels no intervalo determinado e atribuindo as cores.
        int i,j,k;
        for(i=x0;i<x1;i++){
          for(j=y0;j<y1;j++){
            for(k=z0;k<z1;k++){
                putVoxel(i,j,k);
            }
        }
    }
}
    }

void Sculptor::cutBox(int x0, int x1, int y0, int y1, int z0, int z1){
    for (int i = x0; i<x1; i++){
        for (int j = y0; j < y1; j++){
            for (int k = z0; k < z1; k++){
                v[i][j][k].r = r;
                v[i][j][k].g = g;
                v[i][j][k].b = b;
                v[i][j][k].a = a;
                v[i][j][k].isOn = false;

            }
        }
    }
}

void Sculptor::putSphere(int xcenter, int ycenter, int zcenter, int radius){
    //Verificação das dimensões atribuida.
    // if(xcenter<0 || xcenter>nx || ycenter<0 || ycenter>ny || zcenter<0 || zcenter>nz || (radius+xcenter)>nx || (radius+ycenter)>ny || (radius+zcenter)>nz || radius < 0){
    //     exit(1);
    // }
    //Análisando os Voxels no intervalo determinado e atribuindo as cores.
    // else{
        //Variavel para armazenar o raio efetuando a transformação de int para double.
        double rd=radius/2.0;
        //Variavel para a distância da esfera em relação a todos os Voxel.
        double dist;
        for(int i=0;i<nx;i++){
            for(int j=0;j<ny;j++){
                for(int k=0;k<nz;k++){
                    //Equação da esfera.
                    dist = (i-xcenter / 2.0 ) * (i-xcenter / 2.0 ) / (rd * rd) +
                              (j-ycenter / 2.0 ) * (j-ycenter / 2.0 ) /(rd * rd) +
                              (k-zcenter / 2.0 ) * (k-zcenter / 2.0 ) / (rd * rd);
                    //Condição para efetuar o desenho da esfera.
                    if(dist<=1.0){
                        v[i][j][k].isOn=true;
                        v[i][j][k].r=r;
                        v[i][j][k].b=b;
                        v[i][j][k].g=g;
                        v[i][j][k].a=a;
                    }
                }
            }
        }
    // }
}

void Sculptor::cutSphere(int xcenter, int ycenter, int zcenter, int radius){
    //Verificação das dimensões atribuida.
    if(xcenter<0 || xcenter>nx || ycenter<0 || ycenter>ny || zcenter<0 || zcenter>nz || (radius+xcenter)>nx || (radius+ycenter)>ny || (radius+zcenter)>nz || radius < 0){
        exit(1);
    }
    //Análisando os Voxels no intervalo determinado e atribuindo as cores.
    else{
        //Variavel para armazenar o raio efetuando a transformação de int para double.
        double rd=radius/2.0;
        //Variavel para a distância da esfera em relação a todos os Voxel.
        double dist;
        for(int i=0;i<nx;i++){
            for(int j=0;j<ny;j++){
                for(int k=0;k<nz;k++){
                    //Equação da esfera.
                    dist = (i-xcenter / 2.0 ) * (i-xcenter / 2.0 ) / (rd * rd) +
                              (j-ycenter / 2.0 ) * (j-ycenter / 2.0 ) /(rd * rd) +
                              (k-zcenter / 2.0 ) * (k-zcenter / 2.0 ) / (rd * rd);
                    //Condição para efetuar o desenho da esfera.
                    if(dist<=1.0){
                        v[i][j][k].isOn=false;
                        v[i][j][k].r=r;
                        v[i][j][k].b=b;
                        v[i][j][k].g=g;
                        v[i][j][k].a=a;
                    }
                }
            }
        }
    }
}

void Sculptor::putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz){
    //Verificação das dimensões atribuida.
    if(xcenter < 0 || xcenter > nx || ycenter < 0 || ycenter > ny || zcenter < 0 || zcenter > nz || (xcenter + rx) > nx || (ycenter+ry)>ny || 
    (zcenter + rz) > nz || rx < 0 || ry < 0 || rz < 0){
        cout <<"Dimensoes erradas, digite novamente"<<endl;
        exit(1);
    }
    else{
        //Variaveis para armazenarem os raios, assim, efetuando a transformação de int para double.
        double _rx = (rx/2.0), _ry = (ry/2.0), _rz = (rz/2.0);
        //Variavel para a distância da esfera em relação a todos os Voxel.
        double dist;
        for(int i = 0; i < nx; i++){
            for(int j = 0; j < ny; j++){
                for(int k = 0; k < nz; k++){
                    //Equação da elipsóide.
                    dist = ((i - xcenter) / 2.0 ) * ((i - xcenter) / 2.0 ) / (_rx * _rx) +
                    ((j - ycenter) / 2.0 ) * ((j - ycenter) / 2.0 ) /(_ry * _ry) +
                    ((k - zcenter) / 2.0 ) * ((k - zcenter) / 2.0 ) / (_rz * _rz);
                    //Condição para efetuar o desenho da elipsóide.
                    if((dist <= 1) && (i < nx && i >= 0) && (j < ny && j >= 0) && (k < nz && k >= 0)){
                        v[i][j][k].isOn=true;
                        v[i][j][k].r=r;
                        v[i][j][k].b=b;
                        v[i][j][k].g=g;
                        v[i][j][k].a=a;
                    }
                }
            }
        }
    }
}

void Sculptor::cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz){
    //Verificação das dimensões atribuida.
    if(xcenter<0 || xcenter>nx || ycenter<0 || ycenter>ny || zcenter<0 || zcenter>nz || (xcenter+rx)>nx || (ycenter+ry)>ny || (zcenter+rz)>nz || rx<0 || ry<0 || rz<0){
        cout <<"Dimensoes erradas, digite novamente"<<endl;
        exit(1);
    }
    else{
        //Variaveis para armazenarem os raios, assim, efetuando a transformação de int para double.
        double _rx=rx/2.0,_ry=ry/2.0,_rz=rz/2.0;
        //Variavel para a distância da esfera em relação a todos os Voxel.
        double dist;
        for(int i=0;i<nx;i++){
            for(int j=0;j<ny;j++){
                for(int k=0;k<nz;k++){
                    //Equação da elipsóide.
                    dist = (i-xcenter / 2.0 ) * (i-xcenter / 2.0 ) / (_rx * _rx) +
                    (j-ycenter / 2.0 ) * (j-ycenter / 2.0 )/(_ry * _ry) +
                    (k-zcenter / 2.0 ) * (k-zcenter / 2.0 )/(_rz * _rz);
                    //Condição para efetuar o corte da elipsóide.
                    if(dist<=1){
                        v[i][j][k].isOn=false;
                    }
                }
            }
        }
    }
}