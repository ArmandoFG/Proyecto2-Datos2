//
// Created by brayan on 9/7/20.
//
#include <cmath>
#include <iostream>
#include "Matrix.h"
#include <cmath>

float Matrix::xMin[5];
float Matrix::xMax[5];
float Matrix::yMax[5];
float Matrix::yMin[5];


//int** Matrix::generateMatrix1Rutas() {
//    int** matrix = generateMatrix1();

//    float matrisPuntosDeRuta[4][3]={{5,5,5},
//                                    {5,5,5},
//                                    {5,5,5},
//                                    {5,5,5}};
//}

/**
 * @brief Genera matriz del nivel 1
 * 
 * @return int** Matriz
 */
int** Matrix::generateMatrix1() {
    float maxX=1.865802;
    float minX=-1.346433;
    float minY=-0.765199;
    float maxY=1.58003;

    float posX;
    float posY;

    float const posXini=-1.506101;

    posX=posXini;
    posY=1.695585;

    int const x=SIZEX;
    int const y=SIZEY;

    float stepX=(float )(1.945722-posX)/x;
    float stepY=(float )-(0.9060332+posY)/y;


    xMin[0]=posXini*10;
    xMax[0]=1.945722*10;
    yMin[0]=-0.9060332*10;
    yMax[0]=posY*10;

    int **map= new int * [x];

    for ( size_t i = 0; i < x; i++ ) {
        map[i] = new int [y];
        for ( size_t j = 0; j < y; j++ ) {
            map[i][j]=0;
        }
    }

    std::pair<std::pair<float, float>, std::pair<float, float>> lines[17];

    lines[0]=std::make_pair(std::make_pair(0.3961737,0.32721),std::make_pair(0.3897823,0.7537717));
    lines[1]=std::make_pair(std::make_pair(1.659773,0.7332771),std::make_pair(0.3897823,0.7537717));
    lines[2]=std::make_pair(std::make_pair(1.659773,0.7332771),std::make_pair(1.65338,1.358256));
    lines[3]=std::make_pair(std::make_pair(-1.191897,1.382526),std::make_pair(1.65338,1.358256));
    lines[4]=std::make_pair(std::make_pair(-1.191897,1.382526),std::make_pair(-1.179603,0.040144));
    lines[5]=std::make_pair(std::make_pair(0.2771788,0.04425133),std::make_pair(-1.179603,0.040144));
    lines[6]=std::make_pair(std::make_pair(0.2771788,0.04425133),std::make_pair(0.2791546,-0.5461569));
    lines[7]=std::make_pair(std::make_pair(0.2791546,-0.5461569),std::make_pair(0.2791546,-0.5461569));
    lines[8]=std::make_pair(std::make_pair(0.2791546,-0.5461569),std::make_pair(0.4009692,-0.5460777));
    lines[9]=std::make_pair(std::make_pair(0.4080485,0.1176059),std::make_pair(0.4009692,-0.5460777));
    lines[10]=std::make_pair(std::make_pair(0.4080485,0.1176059),std::make_pair(-1.060647,0.1253159));
    lines[11]=std::make_pair(std::make_pair(-1.047301,1.297969),std::make_pair(-1.060647,0.1253159));
    lines[12]=std::make_pair(std::make_pair(-1.047301,1.297969),std::make_pair(1.523449,1.305332));
    lines[13]=std::make_pair(std::make_pair(1.549175,0.8527526),std::make_pair(1.523449,1.305332));
    lines[14]=std::make_pair(std::make_pair(1.549175,0.8527526),std::make_pair(0.2731338,0.8594832));
    lines[15]=std::make_pair(std::make_pair(0.2736665,0.3481684),std::make_pair(0.2731338,0.8594832));
    lines[16]=std::make_pair(std::make_pair(0.2736665,0.3481684),std::make_pair(0.3859036,0.3421134));

    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            if(posX<=minX || posX>=maxX || posY>=maxY|| posY<=minY){
                map[i][j]=1;
            }else{
                int linesAtRigth = 0;

                for(std::pair<std::pair<float, float>, std::pair<float, float>> line :lines){
                    if((line.first.second<posY && line.second.second>posY)
                       || (line.first.second>posY && line.second.second<posY)){
                        double m = (line.second.second-line.first.second)/(line.second.first-line.first.first);
                        //Se chequea si esta a la derecha
                        double yprima=m*(posX-line.first.first) + line.first.second;
                        if((m>0 && posY>yprima) || (m<0 && posY<yprima)){
                            linesAtRigth++;
                        }
                    }
                }
                if(linesAtRigth%2==1){
                    map[i][j]=1;
                }
            }
            posX+=stepX;
        }
        posX=posXini;
        posY+=stepY;
    }

    
    return map;
}
/**
 * @brief Genera matriz del nivel 2
 * 
 * @return int** Matriz
 */
int** Matrix::generateMatrix2() {

    float posX;
    float posY;

    float const posXini=-2.577373;
    posY=3.407662;

    posX=posXini;
    int const x=SIZEX;
    int const y=SIZEY;

    float stepX=(float )(2.543712-posX)/x;
    float stepY=(float )-(3.435781+posY)/y;

    xMin[1]=posXini*5;
    xMax[1]=2.543712*5;
    yMin[1]=-3.435781*5;
    yMax[1]=posY*5;

    int **map= new int * [x];

    for ( size_t i = 0; i < x; i++ ) {
        map[i] = new int [y];
        for ( size_t j = 0; j < y; j++ ) {
            map[i][j]=0;
        }
    }

    std::pair<std::pair<float, float>, std::pair<float, float>> boxes[4];
    boxes[0]=std::make_pair(std::make_pair(0.6890545,-1.178312),std::make_pair(1.733361,0.3004422));
    boxes[1]=std::make_pair(std::make_pair(-0.6845024,-0.1692853),std::make_pair(2.369005,0.2786961));
    boxes[2]=std::make_pair(std::make_pair(-1.280682,-2.230153),std::make_pair(2.23652,0.278697));
    boxes[3]=std::make_pair(std::make_pair(-1.111396,2.259619),std::make_pair(2.54565,0.2787466));

    std::pair<std::pair<float, float>, std::pair<float, float>> lines[19];
    lines[0]=std::make_pair(std::make_pair(0.1758149,3.465088),std::make_pair(0.1516161,3.319467));
    lines[1]=std::make_pair(std::make_pair(0.1527861,2.817741),std::make_pair(0.1516161,3.319467));
    lines[2]=std::make_pair(std::make_pair(0.1527861,2.817741),std::make_pair(2.390024,2.827634));
    lines[3]=std::make_pair(std::make_pair(2.425073,1.389594),std::make_pair(2.390024,2.827634));
    lines[4]=std::make_pair(std::make_pair(2.425073,1.389594),std::make_pair(-0.5659307,1.392535));
    lines[5]=std::make_pair(std::make_pair(-0.5534062,1.084244),std::make_pair(-0.5659307,1.392535));
    lines[6]=std::make_pair(std::make_pair(-0.5534062,1.084244),std::make_pair(2.388678,1.110824));
    lines[7]=std::make_pair(std::make_pair(2.401255,-3.240108),std::make_pair(2.388678,1.110824));
    lines[8]=std::make_pair(std::make_pair(2.401255,-3.240108),std::make_pair(-2.345608,-3.247449));
    lines[9]=std::make_pair(std::make_pair(-2.345607,-2.743659),std::make_pair(-2.345608,-3.247449));
    lines[10]=std::make_pair(std::make_pair(-2.345607,-2.743659),std::make_pair(-2.321032,-1.723793));
    lines[11]=std::make_pair(std::make_pair(-2.314832,2.815091),std::make_pair(-2.321032,-1.723793));
    lines[12]=std::make_pair(std::make_pair(-2.314832,2.815091),std::make_pair(-0.1715524,2.802376));
    lines[13]=std::make_pair(std::make_pair(-0.1797283,3.427794),std::make_pair(-0.1715524,2.802376));
    lines[14]=std::make_pair(std::make_pair(-0.1797283,3.427794),std::make_pair(-2.561372,3.427794));
    lines[15]=std::make_pair(std::make_pair(-2.577373,-3.435781),std::make_pair(-2.561372,3.427794));
    lines[16]=std::make_pair(std::make_pair(-2.577373,-3.435781),std::make_pair(2.543712,-3.435781));
    lines[17]=std::make_pair(std::make_pair(2.533709,3.407),std::make_pair(2.543712,-3.435781));
    lines[18]=std::make_pair(std::make_pair(2.533709,3.407),std::make_pair(0.1449,3.401335));


    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            int linesAtRigth = 0;
            for(std::pair<std::pair<float, float>, std::pair<float, float>> line :lines){
                if((line.first.second<posY && line.second.second>posY)
                   || (line.first.second>posY && line.second.second<posY)){
                    //Se chequea si esta a la derecha
                    if(line.first.first>posX){
                        linesAtRigth++;
                    }
                }
            }
            if(linesAtRigth%2==1){
                map[i][j]=1;
            } else{
                map[i][j]=0;
            }
            for(std::pair<std::pair<float, float>, std::pair<float, float>> box :boxes){
                //Se chequea si esta adentro
                if(posX>=box.first.first-box.second.first/2
                   && posX<=box.first.first+box.second.first/2
                   && posY>=box.first.second-box.second.second/2
                   && posY<=box.first.second+box.second.second/2
                        ){
                    map[i][j]=1;
                }
            }
            posX+=stepX;
            std::cout<<map[i][j];
        }
        posX=posXini;
        std::cout<<"\n";
        posY+=stepY;
    }
    return map;
}
/**
 * @brief Genera matriz del nivel 3
 * 
 * @return int** Matriz
 */
int** Matrix::generateMatrix3() {
    float posX;
    float posY;

    float const posXini=-2.510544-0.1741481/2;
    posY=3.294635+0.2907295/2;

    posX=posXini;
    int const x=SIZEX;
    int const y=SIZEY;

    float stepX=(float )(2.501808+0.1563845/2-posX)/x;
    float stepY=(float )-(3.294635+0.2907293/2+posY)/y;

    xMin[2]=posXini*5;
    xMax[2]=(2.501808+0.1563845/2)*5;
    yMin[2]=(-3.294635-0.2907293/2)*5;
    yMax[2]=posY*5;

    int **map= new int * [x];

    for ( size_t i = 0; i < x; i++ ) {
        map[i] = new int [y];
        for ( size_t j = 0; j < y; j++ ) {
            map[i][j]=0;
        }
    }

    std::pair<std::pair<float, float>, std::pair<float, float>> boxes[13];
    boxes[0]=std::make_pair(std::make_pair(0,-3.294635),std::make_pair(5.16,0.2907293));
    boxes[1]=std::make_pair(std::make_pair(2.501808,-0.8280637),std::make_pair(0.1563845,5.223873));
    boxes[2]=std::make_pair(std::make_pair(-2.510544,0),std::make_pair(0.1741481,6.88));
    boxes[3]=std::make_pair(std::make_pair(-0.9954384,-1.523989),std::make_pair(3.169123,0.3083477));
    boxes[4]=std::make_pair(std::make_pair(-0.3876052,-1.039484),std::make_pair(0.2620921,2.792537));
    boxes[5]=std::make_pair(std::make_pair(-1.453517,-2.91584),std::make_pair(0.2092361,1.04832));
    boxes[6]=std::make_pair(std::make_pair(0.9954368,-2.748466),std::make_pair(0.244475,1.383069));
    boxes[7]=std::make_pair(std::make_pair(1.021865,1.594463),std::make_pair(3.116269,0.308347));
    boxes[8]=std::make_pair(std::make_pair(2.04373,-1.849928),std::make_pair(1.072539,0.2554924));
    boxes[9]=std::make_pair(std::make_pair(0.4185932,2.501809),std::make_pair(0.1916175,1.876383));
    boxes[10]=std::make_pair(std::make_pair(-1.44046,1.21142),std::make_pair(0.2268567,1.101176));
    boxes[11]=std::make_pair(std::make_pair(-1.378481,2.585968),std::make_pair(1.777272,0.3083477));
    boxes[12]=std::make_pair(std::make_pair(-1.015998,3.423958),std::make_pair(3.0138,0.03334141));


    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            for(std::pair<std::pair<float, float>, std::pair<float, float>> box :boxes){
                //Se chequea si esta adentro
                if(posX>=box.first.first-box.second.first/2
                   && posX<=box.first.first+box.second.first/2
                   && posY>=box.first.second-box.second.second/2
                   && posY<=box.first.second+box.second.second/2
                        ){
                    map[i][j]=1;
                }
            }

            posX+=stepX;

            std::cout<<map[i][j];
        }
        std::cout<<"\n";
        posX=posXini;
        posY+=stepY;

    }

    return map;
}
/**
 * @brief Genera matriz del nivel 4
 * 
 * @return int** Matriz
 */
int** Matrix::generateMatrix4() {
    float posX;
    float posY;

    float const posXini=-2.385236;
    posY=3.429452;

    posX=posXini;
    int const x=SIZEX;
    int const y=SIZEY;

    int **map= new int * [x];

    float stepX=(float )(2.426883-posX)/x;
    float stepY=(float )-(3.098883+posY)/y;

    xMin[3]=posXini*5;
    xMax[3]=2.426883*5;
    yMin[3]=-3.098883*5;
    yMax[3]=posY*5;


    for ( size_t i = 0; i < x; i++ ) {
        map[i] = new int [y];
        for ( size_t j = 0; j < y; j++ ) {
            map[i][j]=0;
        }
    }

    std::pair<std::pair<float, float>, std::pair<float, float>> boxes[13];
    boxes[0]=std::make_pair(std::make_pair(-0.3769179,1.034334),std::make_pair(0.1987051,2.111545));
    boxes[1]=std::make_pair(std::make_pair(-0.9203816,0.1490138),std::make_pair(1.25057,0.3409044));
    boxes[2]=std::make_pair(std::make_pair(0.9730003,0.3506214),std::make_pair(0.2338164,1.375238));
    boxes[3]=std::make_pair(std::make_pair(0.6398845,0.1665456),std::make_pair(0.93501,0.3409055));
    boxes[4]=std::make_pair(std::make_pair(0.03506237,1.21841),std::make_pair(1.022666,0.3409052));
    boxes[5]=std::make_pair(std::make_pair(-1.761873,1.192113),std::make_pair(0.1987057,1.094741));
    boxes[6]=std::make_pair(std::make_pair(1.323597,-1.200879),std::make_pair(0.2337668,1.042149));
    boxes[7]=std::make_pair(std::make_pair(1.577798,-1.20088),std::make_pair(0.7071061,0.3058423));
    boxes[8]=std::make_pair(std::make_pair(-0.03506182,-1.218411),std::make_pair(0.2863601,1.042149));
    boxes[9]=std::make_pair(std::make_pair(0.1840765,-1.218411),std::make_pair(0.7246372,0.3058424));
    boxes[10]=std::make_pair(std::make_pair(-0.3769179,-2.077434),std::make_pair(0.2688295,0.7265873));
    boxes[11]=std::make_pair(std::make_pair(-1.455079,-1.0431),std::make_pair(0.2512989,1.427833));
    boxes[12]=std::make_pair(std::make_pair(-1.981012,-1.192115),std::make_pair(1.197977,0.3233733));

    std::pair<std::pair<float, float>, std::pair<float, float>> lines[38];
    lines[0]=std::make_pair(std::make_pair(0.523513,3.073488),std::make_pair(0.5557855,2.794999));
    lines[1]=std::make_pair(std::make_pair(1.169188,2.797978),std::make_pair(0.5557855,2.794999));
    lines[2]=std::make_pair(std::make_pair(1.169188,2.797978),std::make_pair(1.177355,2.447335));
    lines[3]=std::make_pair(std::make_pair(1.882792,2.453891),std::make_pair(1.177355,2.447335));
    lines[4]=std::make_pair(std::make_pair(1.882792,2.453891),std::make_pair(1.878365,2.208471));
    lines[5]=std::make_pair(std::make_pair(1.86429,2.050333),std::make_pair(1.878365,2.208471));
    lines[6]=std::make_pair(std::make_pair(1.86429,2.050333),std::make_pair(0.8812152,2.04221));
    lines[7]=std::make_pair(std::make_pair(0.8809078,1.759764),std::make_pair(0.8812152,2.04221));
    lines[8]=std::make_pair(std::make_pair(0.8809078,1.759764),std::make_pair(1.894064,1.768565));
    lines[9]=std::make_pair(std::make_pair(1.880747,2.030602),std::make_pair(1.894064,1.768565));
    lines[10]=std::make_pair(std::make_pair(1.880747,2.030602),std::make_pair(1.891304,2.077742));
    lines[11]=std::make_pair(std::make_pair(2.426883,2.08892),std::make_pair(1.891304,2.077742));
    lines[12]=std::make_pair(std::make_pair(2.426883,2.08892),std::make_pair(2.395229,-2.072324));
    lines[13]=std::make_pair(std::make_pair(1.858482,-2.053136),std::make_pair(2.395229,-2.072324));
    lines[14]=std::make_pair(std::make_pair(1.858482,-2.053136),std::make_pair(1.83117,-2.411874));
    lines[15]=std::make_pair(std::make_pair(1.176483,-2.406844),std::make_pair(1.83117,-2.411874));
    lines[16]=std::make_pair(std::make_pair(1.176483,-2.406844),std::make_pair(1.162829,-2.771571));
    lines[17]=std::make_pair(std::make_pair(0.5141679,-2.759002),std::make_pair(1.162829,-2.771571));
    lines[18]=std::make_pair(std::make_pair(0.5141679,-2.759002),std::make_pair(0.5311329,-3.066483));
    lines[19]=std::make_pair(std::make_pair(-0.4680389,-3.098883),std::make_pair(0.5311329,-3.066483));
    lines[20]=std::make_pair(std::make_pair(-0.4680389,-3.098883),std::make_pair(-0.5089878,-2.739259));
    lines[21]=std::make_pair(std::make_pair(-1.192661,-2.726238),std::make_pair(-0.5089878,-2.739259));
    lines[22]=std::make_pair(std::make_pair(-1.192661,-2.726238),std::make_pair(-1.196069,-2.364724));
    lines[23]=std::make_pair(std::make_pair(-1.856314,-2.398438),std::make_pair(-1.196069,-2.364724));
    lines[24]=std::make_pair(std::make_pair(-1.856314,-2.398438),std::make_pair(-1.86599,-2.034106));
    lines[25]=std::make_pair(std::make_pair(-2.385236,-2.034304),std::make_pair(-1.86599,-2.034106));
    lines[26]=std::make_pair(std::make_pair(-2.385236,-2.034304),std::make_pair(-2.359861,2.092051));
    lines[27]=std::make_pair(std::make_pair(-1.891614,2.105363),std::make_pair(-2.359861,2.092051));
    lines[28]=std::make_pair(std::make_pair(-1.891614,2.105363),std::make_pair(-1.868299,2.481336));
    lines[29]=std::make_pair(std::make_pair(-1.15357,2.48364),std::make_pair(-1.868299,2.481336));
    lines[30]=std::make_pair(std::make_pair(-1.15357,2.48364),std::make_pair(-1.171446,2.804253));
    lines[31]=std::make_pair(std::make_pair(-0.5074055,2.814798),std::make_pair(-1.171446,2.804253));
    lines[32]=std::make_pair(std::make_pair(-0.5074055,2.814798),std::make_pair(-0.5020517,3.099518));
    lines[33]=std::make_pair(std::make_pair(-0.1688647,3.134092),std::make_pair(-0.5020517,3.099518));
    lines[34]=std::make_pair(std::make_pair(-0.1688647,3.134092),std::make_pair(-0.1621634,3.429452));
    lines[35]=std::make_pair(std::make_pair(0.1786746,3.425632),std::make_pair(-0.1621634,3.429452));
    lines[36]=std::make_pair(std::make_pair(0.1786746,3.425632),std::make_pair(0.1853982,3.120261));
    lines[37]=std::make_pair(std::make_pair(0.5147375,3.113836),std::make_pair(0.1853982,3.120261));


    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            int linesAtRigth = 0;
            for(std::pair<std::pair<float, float>, std::pair<float, float>> line :lines){
                if((line.first.second<posY && line.second.second>posY)
                   || (line.first.second>posY && line.second.second<posY)){
                    double m = (line.second.second-line.first.second)/(line.second.first-line.first.first);
                    //Se chequea si esta a la derecha
                    double yprima=m*(posX-line.first.first) + line.first.second;
                    if((m>0 && posY>yprima) || (m<0 && posY<yprima)){
                        linesAtRigth++;
                    }
                }
            }
            if(linesAtRigth%2==1){
                map[i][j]=0;
            } else{
                map[i][j]=1;
            }
            for(std::pair<std::pair<float, float>, std::pair<float, float>> box :boxes){
                //Se chequea si esta adentro
                if(posX>=box.first.first-box.second.first/2
                   && posX<=box.first.first+box.second.first/2
                   && posY>=box.first.second-box.second.second/2
                   && posY<=box.first.second+box.second.second/2
                        ){
                    map[i][j]=1;
                }
            }
            posX+=stepX;
            std::cout<<map[i][j];
        }
        posX=posXini;
        std::cout<<"\n";
        posY+=stepY;
    }
    return map;
}
/**
 * @brief Genera matriz del nivel 5
 * 
 * @return int** Matriz
 */

int** Matrix::generateMatrix5() {
    float posX;
    float posY;

    float const posXini=-2.559767-0.04046583/2;
    posY=3.413361+0.05327868/2;

    posX=posXini;
    int const x=SIZEX;
    int const y=SIZEY;

    float stepX=(float )(2.559765+0.04047036/2-posX)/x;
    float stepY=(float )-(3.413362+0.05327725/2+posY)/y;

    xMin[4]=posXini*5;
    xMax[4]=(2.559765+0.04047036/2)*5;
    yMin[4]=(-3.413362-0.05327725/2)*5;
    yMax[4]=posY*5;


    int **map= new int * [x];

    for ( size_t i = 0; i < x; i++ ) {
        map[i] = new int [y];
        for ( size_t j = 0; j < y; j++ ) {
            map[i][j]=0;
        }
    }


    std::pair<std::pair<float, float>, std::pair<float, float>> boxes[10];
    boxes[0]=std::make_pair(std::make_pair(-0.6067969,-2.221033),std::make_pair(0.07106328,2.388376));
    boxes[1]=std::make_pair(std::make_pair(0.6883833,-2.248719),std::make_pair(0.07106304,2.382562));
    boxes[2]=std::make_pair(std::make_pair(2.559765,0),std::make_pair(0.04047036,6.88));
    boxes[3]=std::make_pair(std::make_pair(-0.7179254,-3.195916),std::make_pair(0.4199085,0.4832973));
    boxes[4]=std::make_pair(std::make_pair(0.7991344,-3.190347),std::make_pair(0.4395276,0.4993067));
    boxes[5]=std::make_pair(std::make_pair(0.811525,-1.976157),std::make_pair(0.4643056,0.7718787));
    boxes[6]=std::make_pair(std::make_pair(-0.7000183,-1.969961),std::make_pair(0.4643056,0.8338289));
    boxes[7]=std::make_pair(std::make_pair(0,-3.413362),std::make_pair(5.16,0.05327725));
    boxes[8]=std::make_pair(std::make_pair(0,3.413361),std::make_pair(5.16,0.05327725));
    boxes[9]=std::make_pair(std::make_pair(-1.356031,-1.195449),std::make_pair(0.3576695,0.3219833));

    std::pair<std::pair<float, float>, std::pair<float, float>> lines[4];
    lines[0]=std::make_pair(std::make_pair(-1.706157,0.0004076004),std::make_pair(-1.955679,-0.01228752));
    lines[1]=std::make_pair(std::make_pair(-1.935856,-1.042835),std::make_pair(-1.955679,-0.01228752));
    lines[2]=std::make_pair(std::make_pair(-1.935856,-1.042835),std::make_pair(-0.6262863,-1.034991));
    lines[3]=std::make_pair(std::make_pair(-1.706157,0.0004076004),std::make_pair(-0.6262863,-1.034991));

    std::pair<std::pair<float, float>, std::pair<float, float>> line1[9];
    line1[0]=std::make_pair(std::make_pair(1.959759,-0.009638977),std::make_pair(1.961241,-1.025579));
    line1[1]=std::make_pair(std::make_pair(1.545361,-1.031822),std::make_pair(1.961241,-1.025579));
    line1[2]=std::make_pair(std::make_pair(1.545361,-1.031822),std::make_pair(1.527112,-1.455899));
    line1[3]=std::make_pair(std::make_pair(1.210562,-1.444552),std::make_pair(1.527112,-1.455899));
    line1[4]=std::make_pair(std::make_pair(1.210562,-1.444552),std::make_pair(1.205524,-1.039037));
    line1[5]=std::make_pair(std::make_pair(0.9792609,-1.060015),std::make_pair(1.205524,-1.039037));
    line1[6]=std::make_pair(std::make_pair(0.9792609,-1.060015),std::make_pair(0.7219454,-1.043258));
    line1[7]=std::make_pair(std::make_pair(1.780526,0.01554718),std::make_pair(0.7219454,-1.043258));
    line1[8]=std::make_pair(std::make_pair(1.780526,0.01554718),std::make_pair(1.924579,0));

    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            for(std::pair<std::pair<float, float>, std::pair<float, float>> box :boxes){
                //Se chequea si esta adentro
                if(posX>=box.first.first-box.second.first/2
                   && posX<=box.first.first+box.second.first/2
                   && posY>=box.first.second-box.second.second/2
                   && posY<=box.first.second+box.second.second/2
                        ){
                    map[i][j]=1;
                }
                int linesAtRigth = 0;
                for(std::pair<std::pair<float, float>, std::pair<float, float>> line :lines){
                    if((line.first.second<=posY && line.second.second>=posY)
                       || (line.first.second>=posY && line.second.second<=posY)){
                        double m = (line.second.second-line.first.second)/(line.second.first-line.first.first);
                        //Se chequea si esta a la derecha
                        double yprima=m*(posX-line.first.first) + line.first.second;
                        if((m>0 && posY>yprima) || (m<0 && posY<yprima)){
                            linesAtRigth++;
                        }
                    }
                }
                if(linesAtRigth%2==1){
                    map[i][j]=1;
                }

                linesAtRigth = 0;
                for(std::pair<std::pair<float, float>, std::pair<float, float>> line :line1){
                    if((line.first.second<=posY && line.second.second>=posY)
                       || (line.first.second>=posY && line.second.second<=posY)){
                        double m = (line.second.second-line.first.second)/(line.second.first-line.first.first);
                        //Se chequea si esta a la derecha
                        double yprima=m*(posX-line.first.first) + line.first.second;
                        if((m>0 && posY>yprima) || (m<0 && posY<yprima)){
                            linesAtRigth++;
                        }
                    }
                }
                if(linesAtRigth%2==1){
                    map[i][j]=1;
                }
            }

            posX+=stepX;
            std::cout<<map[i][j];
        }
        posX=posXini;
        posY+=stepY;
        std::cout<<"\n";
    }

    return map;
}
/**
 * @brief Genera coordenadas para el cliente
 * 
 * @param x Posicion x de la matriz
 * @param y Posicion y de la matriz
 * @param matrixNumber Numero de la matriz
 * @return std::pair<float, float> 
 */
std::pair<float, float> Matrix::toPoint(int x, int y, int matrixNumber) {
    int temp=x;
    x=y;
    y=temp;
    int n=matrixNumber-1;
    float stepx=(xMax[n]-xMin[n])/(SIZEX);
    float xfinal=xMin[n]+stepx/2+stepx*(float)(x);
    float stepy=(yMax[n]-yMin[n])/(SIZEY);
    float yfinal=yMax[n]-stepy/2-stepy*(float)(y);
    cout << xfinal << endl;
    cout << yfinal << endl;

    return {xfinal, yfinal};
}

std::pair<int, int> Matrix::toMatrixPosition(float x, float y, int matrixNumber, int** matrix) {
    int n=matrixNumber-1;
    float xfinalf=(x-xMin[n])*(SIZEX)/(xMax[n]-xMin[n]);
    float yfinalf=(-y+yMax[n])*(SIZEY)/(yMax[n]-yMin[n]);
    int xfinal = (int)std::floor(xfinalf);
    int yfinal = (int)std::floor(yfinalf);

    if(matrix[yfinal][xfinal]==1){
        xfinal=(int)std::floor(xfinalf);
        yfinal=(int)std::ceil(yfinalf);
        if(yfinal==SIZEY){
            yfinal--;
        }
        if(matrix[yfinal][xfinal]==1) {
            xfinal = (int) std::ceil(xfinalf);
            yfinal = (int) std::floor(yfinalf);
            if(xfinal==SIZEX){
                xfinal--;
            }
            if (matrix[yfinal][xfinal] == 1) {
                xfinal = (int) std::ceil(xfinalf);
                yfinal = (int) std::ceil(yfinalf);
                if(yfinal==SIZEY){
                    yfinal--;
                }
                if(xfinal==SIZEX){
                    xfinal--;
                }
            }
        }
    }
    return {yfinal,xfinal};
}

/**
 * @brief Matris nivel 1 con rutas de espectros
 * 
 * @return int** Matriz
 */

int** Matrix::rutasMatrix1(){
    //Genera matriz 1

    //Genera las rutas
    int **map = generateMatrix1();
    for(int i = 24; i < 29; i++){
        map[9][i] = 2;
    }
    map[13][26] = 2;

    int i = 10;
    for(int j = 23; map[i][j] != 2; j++){
        map[i][j] = 2;
        i++;
    }
    i = 12;
    for(int j = 27; j != 30; j++){
        map[i][j] = 2;
        i--;
    }

    map[33][5] = 3;
    map[33][19] = 3;
    map[39][19] = 3;
    map[39][5] = 3;

    i = 33;
    for(int j = 6; map[i][j] != 3; j++){
        map[i][j] = 3;  
    }
    int j = 19;
    for(int  i = 34; map[i][j] != 3; i++){
        map[i][j] = 3;  
    }
    i = 39;
    for(int j = 18; map[i][j] != 3; j--){
        map[i][j] = 3;  
    }
    j = 5;
    for(int  i = 38; map[i][j] != 3; i--){
        map[i][j] = 3;  
    }
    map[33][5] = 0;
    map[33][19] = 0;
    map[39][19] = 0;
    map[39][5] = 0;

    map[33][41] = 4;
    map[37][37] = 4;
    map[41][41] = 4;
    map[37][45] = 4;

    i = 34;
    for(int j = 40; map[i][j] != 4; j--){
        map[i][j] = 4; 
        i++; 
    }
    i = 38;
    for(int j = 38; map[i][j] != 4; j++){
        map[i][j] = 4; 
        i++; 
    }
    i = 40;
    for(int j = 42; map[i][j] != 4; j++){
        map[i][j] = 4; 
        i--; 
    }
    i = 36;
    for(int j = 44; map[i][j] != 4; j--){
        map[i][j] = 4; 
        i--; 
    }

    return map;
}
void Matrix::print(int** matrix) {
    for(int i=0;i<SIZEX;i++){
        for(int j=0;j<SIZEY;j++){
            cout<<to_string(matrix[i][j])+" ";
        }
        cout<<"\n";
    }
}

/**
 * @brief Matris nivel 2 con rutas de espectros
 * 
 * @return int** Matriz
 */
int** Matrix::rutasMatrix2(){
    //Genera matriz nivel 2

    // Traza las rutas
    int **map = generateMatrix2();
    for(int i = 24; i < 29; i++){
        map[10][i] = 2;
    }
    map[14][26] = 2;

    int i = 11;
    for(int j = 23; map[i][j] != 2; j++){
        map[i][j] = 2;
        i++;
    }
    i = 13;
    for(int j = 27; j != 30; j++){
        map[i][j] = 2;
        i--;
    }

    

    map[33][3] = 3;
    map[33][13] = 3;
    map[39][13] = 3;
    map[39][3] = 3;

    i = 33;
    for(int j = 4; map[i][j] != 3; j++){
        map[i][j] = 3;  
    }
    int j = 13;
    for(int  i = 34; map[i][j] != 3; i++){
        map[i][j] = 3;  
    }
    i = 39;
    for(int j = 12; map[i][j] != 3; j--){
        map[i][j] = 3;  
    }
    j = 3;
    for(int  i = 38; map[i][j] != 3; i--){
        map[i][j] = 3;  
    }

     map[33][3] = 0;
    map[33][13] = 0;
    map[39][13] = 0;
    map[39][3] = 0;

    map[25][41] = 4;
    map[29][37] = 4;
    map[33][41] = 4;
    map[29][45] = 4;

    i = 26;
    for(int j = 40; map[i][j] != 4; j--){
        map[i][j] = 4; 
        i++; 
    }
    i = 30;
    for(int j = 38; map[i][j] != 4; j++){
        map[i][j] = 4; 
        i++; 
    }
    i = 32;
    for(int j = 42; map[i][j] != 4; j++){
        map[i][j] = 4; 
        i--; 
    }
    i = 28;
    for(int j = 44; map[i][j] != 4; j--){
        map[i][j] = 4; 
        i--; 
    }

    print(map);
    return map;
}
/**
 * @brief Matris nivel 3 con rutas de espectros
 * 
 * @return int** Matriz
 */

int** Matrix::rutasMatrix3(){
    //Genera mapa nivel 3 

    //Traza las rutas
    int **map = generateMatrix3();
    for(int i = 14; i < 19; i++){
        map[10][i] = 2;
    }
    map[14][16] = 2;

    int i = 11;
    for(int j = 13; map[i][j] != 2; j++){
        map[i][j] = 2;
        i++;
    }
    i = 13;
    for(int j = 17; j != 20; j++){
        map[i][j] = 2;
        i--;
    }


    map[23][33] = 3;
    map[23][43] = 3;
    map[29][43] = 3;
    map[29][33] = 3;

    i = 23;
    for(int j = 34; map[i][j] != 3; j++){
        map[i][j] = 3;  
    }
    int j = 43;
    for(int  i = 24; map[i][j] != 3; i++){
        map[i][j] = 3;  
    }
    i = 29;
    for(int j = 42; map[i][j] != 3; j--){
        map[i][j] = 3;  
    }
    j = 33;
    for(int  i = 28; map[i][j] != 3; i--){
        map[i][j] = 3;  
    }

    map[23][33] = 0;
    map[23][43] = 0;
    map[29][43] = 0;
    map[29][33] = 0;

    map[39][27] = 4;
    map[43][23] = 4;
    map[47][27] = 4;
    map[43][31] = 4;

    i = 40;
    for(int j = 26; map[i][j] != 4; j--){
        map[i][j] = 4; 
        i++; 
    }
    i = 44;
    for(int j = 24; map[i][j] != 4; j++){
        map[i][j] = 4; 
        i++; 
    }
    i = 46;
    for(int j = 28; map[i][j] != 4; j++){
        map[i][j] = 4; 
        i--; 
    }
    i = 42;
    for(int j = 30; map[i][j] != 4; j--){
        map[i][j] = 4; 
        i--; 
    }

    return map;
}

/**
 * @brief Matris nivel 4 con rutas de espectros
 * 
 * @return int** 
 */

int** Matrix::rutasMatrix4(){
    //Genera mapa nivel 4

    //Traza las rutas
    int **map = generateMatrix4();
    for(int i = 22; i < 28; i++){
        map[4][i] = 2;
    }
    map[8][25] = 2;

    int i = 5;
    for(int j = 22; map[i][j] != 2; j++){
        map[i][j] = 2;
        i++;
    }
    i = 7;
    for(int j = 26; j != 29; j++){
        map[i][j] = 2;
        i--;
    }


    map[23][38] = 3;
    map[23][48] = 3;
    map[29][48] = 3;
    map[29][38] = 3;

    i = 23;
    for(int j = 39; map[i][j] != 3; j++){
        map[i][j] = 3;  
    }
    int j = 48;
    for(int  i = 24; map[i][j] != 3; i++){
        map[i][j] = 3;  
    }
    i = 29;
    for(int j = 47; map[i][j] != 3; j--){
        map[i][j] = 3;  
    }
    j = 38;
    for(int  i = 28; map[i][j] != 3; i--){
        map[i][j] = 3;  
    }
    map[23][38] = 0;
    map[23][48] = 0;
    map[29][48] = 0;
    map[29][38] = 0;

    map[39][27] = 4;
    map[43][23] = 4;
    map[47][27] = 4;
    map[43][31] = 4;

    i = 40;
    for(int j = 26; map[i][j] != 4; j--){
        map[i][j] = 4; 
        i++; 
    }
    i = 44;
    for(int j = 24; map[i][j] != 4; j++){
        map[i][j] = 4; 
        i++; 
    }
    i = 46;
    for(int j = 28; map[i][j] != 4; j++){
        map[i][j] = 4; 
        i--; 
    }
    i = 42;
    for(int j = 30; map[i][j] != 4; j--){
        map[i][j] = 4; 
        i--; 
    }

    return map;
}


