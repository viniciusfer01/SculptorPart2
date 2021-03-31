#include "sculptor.h"
#include <cmath>
#include <fstream>
#include <string>
#include <iostream>
#include <cstdlib>



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