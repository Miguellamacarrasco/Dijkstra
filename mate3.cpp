#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

struct ciudad
{
    string nombre;
    vector<pair<ciudad*, int>> costos_viajes;
    void insert(ciudad* city, int peso)
    {
        costos_viajes.push_back(pair<ciudad*,int>(city,peso));
    }
};

int Dijkstra(ciudad* primera_ciudad, ciudad* segunda_ciudad, vector<ciudad*> ciudades)
{
    map<ciudad*, int> distancias;
    for (auto city : ciudades)
    {
        if (city != primera_ciudad)
        {
            distancias.insert(pair<ciudad*, int>(city, 9999999));
        }
    }
    vector<ciudad*> por_visitar;
    vector<ciudad*> vistos;
    bool already_seen = true;
    por_visitar.push_back(primera_ciudad);
    distancias.insert(pair<ciudad*, int>(primera_ciudad, 0));
    while (por_visitar.size() > 0)
    {
        for (auto n: por_visitar.front()->costos_viajes)
        {
            if (distancias[por_visitar.front()] + n.second < distancias[n.first])
            {
                distancias[n.first] = distancias[por_visitar.front()] + n.second;
            }
            
            for (auto n2 : vistos)
            {
                if (n.first == n2)
                {
                    already_seen = false;
                }
            }
            if (already_seen && find(por_visitar.begin(),por_visitar.end(),n.first) == por_visitar.end()) {por_visitar.push_back(n.first);}
        }  
        vistos.push_back(por_visitar.front());
        por_visitar.erase(por_visitar.begin());        
    }
    
    return distancias[segunda_ciudad];
}


int main()
{
    vector<string> nombres = {"Lima", "Cusco", "Trujillo", "Arequipa", "Cajamarca", "Chiclayo", "Iquitos", "Ayacucho"};
    vector<ciudad*> ciudades;
    for (int i = 0; i < 8; i++)
    {
        auto nueva_ciudad = new ciudad;
        ciudades.push_back(nueva_ciudad);
    }
    for (int i = 0; i < 8; i++)
    {
        if (i != 0)
        {
            vector<int> costos = {258, 233, 138, 110, 223, 176, 83};
            ciudades[0]->insert(ciudades[i], costos[i - 1]);
        }
    }
    for (int i = 0; i < 8; i++)
    {
        if (i != 1)
        {
            vector<int> costos = {258, 0, 246, 127, 189, 201, 211, 124};
            ciudades[1]->insert(ciudades[i], costos[i]);
        }
    }
    for (int i = 0; i < 8; i++)
    {
        if (i != 2)
        {
            vector<int> costos = {233, 256, 0, 178, 185, 213, 225, 187};
            ciudades[2]->insert(ciudades[i], costos[i]);
        }
    }
    for (int i = 0; i < 8; i++)
    {
        if (i != 3)
        {
            vector<int> costos = {138, 127, 178, 0, 220, 193, 256, 168};
            ciudades[3]->insert(ciudades[i], costos[i]);
        }
    }
    for (int i = 0; i < 8; i++)
    {
        if (i != 4)
        {
            vector<int> costos = {110, 189, 185, 220, 0, 205, 241, 207};
            ciudades[4]->insert(ciudades[i], costos[i]);
        }
    }
    for (int i = 0; i < 8; i++)
    {
        if (i != 5)
        {
            vector<int> costos = {223, 201, 213, 193, 205, 0, 176, 83};
            ciudades[5]->insert(ciudades[i], costos[i]);
        }
    }
    for (int i = 0; i < 8; i++)
    {
        if (i != 6)
        {
            vector<int> costos = {176, 211, 225, 256, 241, 176, 0, 278};
            ciudades[6]->insert(ciudades[i], costos[i]);
        }
    }
    for (int i = 0; i < 8; i++)
    {
        if (i != 7)
        {
            vector<int> costos = {83, 124, 187, 168, 207, 83, 278, 0};
            ciudades[7]->insert(ciudades[i], costos[i]);
        }
    }
    std::cout << Dijkstra(ciudades[0], ciudades[1], ciudades);
}