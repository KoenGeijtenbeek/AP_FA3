#include <iostream>
#include <type_traits>
#include <queue>
#include "src/include/Graaf.hpp"
#include "src/include/Stap.hpp"
#include "src/include/Station.hpp"
#include "src/include/Autorit.hpp"
#include "src/include/Treinrit.hpp"
#include "src/include/Vlucht.hpp"
#include "src/include/StationGreaterThan.hpp"

int main()
{
    //Graaf 1: Autoritten
    Station a = Station("Amsterdam");
    Station b = Station("Breda");
    Station c = Station("Culemborg");
    Station d = Station("Deventer");
    Station e = Station("Eindhoven");
    Station f = Station("Fleringen");

    Autorit * a1 = new Autorit(&a, &b, 104);
    Autorit * a2 = new Autorit(&a, &c, 62);
    Autorit * b1 = new Autorit(&b, &c, 72);
    Autorit * b2 = new Autorit(&b, &e, 59);
    Autorit * c1 = new Autorit(&c, &d, 106);
    Autorit * c2 = new Autorit(&c, &e, 75);
    Autorit * d1 = new Autorit(&d, &f, 60);
    Autorit * e1 = new Autorit(&e, &d, 132);
    Autorit * e2 = new Autorit(&e, &f, 182);

    a.connections.push_back(a1);
    a.connections.push_back(a2);
    b.connections.push_back(b1);
    b.connections.push_back(b2);
    c.connections.push_back(c1);
    c.connections.push_back(c2);
    d.connections.push_back(d1);
    e.connections.push_back(e1);
    e.connections.push_back(e2);

    Graaf graaf1 = Graaf(
        {&a, &b, &c, &d, &e, &f},
        {a1, a2, b1, b2, c1, c2, d1, e1, e2}
    );

    std::vector<Station*> kortsteAutoRoute = graaf1.dijkstra(graaf1, &a, &f);

    //als test: printen van afstanden die door het algoritme aan de stations zijn toegekend
    //for(Station* station : graaf1.stations){
    //    std::cout << station->afstandTotBron << std::endl;
    //}
    
    //printen van kortste autoroute
    std::cout << "Kortste autoroute van Amsterdam naar Fleringen: " << std::endl;
    for(int i = 0; i < kortsteAutoRoute.size()-1; i++){
        Stap* stap = graaf1.getConnection(kortsteAutoRoute[i], kortsteAutoRoute[i+1]);
        std::cout << *stap;
    }
    std::cout << "Totale afstand: " << f.afstandTotBron << "km" << std::endl << std::endl;
    

    //Graaf 2: Treinritten
    Station g = Station("Groningen");
    Station h = Station("Houten");
    Station i = Station("Ieper");
    Station j = Station("Jena");
    Station k = Station("Karlsruhe");
    Station l = Station("Landshut");
    Station m = Station("Milaan");

    Treinrit * g1 = new Treinrit(&g, &h, 139);
    Treinrit * g2 = new Treinrit(&g, &i, 327);
    Treinrit * g3 = new Treinrit(&g, &j, 459);
    Treinrit * h1 = new Treinrit(&h, &j, 476);
    Treinrit * h2 = new Treinrit(&h, &k, 307);
    Treinrit * i1 = new Treinrit(&i, &h, 260);
    Treinrit * i2 = new Treinrit(&i, &k, 371);
    Treinrit * j1 = new Treinrit(&j, &k, 270);
    Treinrit * j2 = new Treinrit(&j, &l, 250);
    Treinrit * k1 = new Treinrit(&k, &l, 246);
    Treinrit * k2 = new Treinrit(&k, &m, 379);
    Treinrit * l1 = new Treinrit(&l, &m, 463);

    g.connections.push_back(g1);
    g.connections.push_back(g2);
    g.connections.push_back(g3);
    h.connections.push_back(h1);
    h.connections.push_back(h2);
    i.connections.push_back(i1);
    i.connections.push_back(i2);
    j.connections.push_back(j1);
    j.connections.push_back(j2);
    k.connections.push_back(k1);
    k.connections.push_back(k2);
    l.connections.push_back(l1);

    Graaf graaf2 = Graaf(
        {&g, &h, &i, &j, &k, &l, &m},
        {g1, g2, g3, h1, h2, i1, i2, j1, j2, k1, k2, l1}
    );

    std::vector<Station*> kortsteTreinRoute = graaf2.dijkstra(graaf2, &g, &m);

    //printen van kortste treinroute
    std::cout << "Kortste treinroute van Groningen naar Milaan: " << std::endl;
    for(int i = 0; i < kortsteTreinRoute.size()-1; i++){
        Stap* stap = graaf2.getConnection(kortsteTreinRoute[i], kortsteTreinRoute[i+1]);
        std::cout << *stap;
    }
    std::cout << "Totale reistijd: " << m.afstandTotBron/60 << " uur en " << m.afstandTotBron%60 << " minuten" << std::endl << std::endl;


    //Graaf 3: Vluchten
    Station n = Station("New York");
    Station o = Station("Orlando");
    Station p = Station("Portland");
    Station q = Station("Quito");
    Station r = Station("Rotterdam");
    Station s = Station("Seoel");
    Station t = Station("Tashkent");
    Station u = Station("aUckland");
    Station v = Station("Vanuatu");
    Station w = Station("Wellington");

    Vlucht * n1 = new Vlucht(&n, &o, 150);
    Vlucht * n2 = new Vlucht(&n, &p, 350);
    Vlucht * n3 = new Vlucht(&n, &r, 660);
    Vlucht * o1 = new Vlucht(&o, &q, 375);
    Vlucht * p1 = new Vlucht(&p, &s, 825);
    Vlucht * p2 = new Vlucht(&p, &v, 1215);
    Vlucht * q1 = new Vlucht(&q, &u, 1375);
    Vlucht * q2 = new Vlucht(&q, &v, 1475);
    Vlucht * r1 = new Vlucht(&r, &t, 545);
    Vlucht * s1 = new Vlucht(&s, &v, 375);
    Vlucht * t1 = new Vlucht(&t, &v, 790);
    Vlucht * u1 = new Vlucht(&u, &w, 65);
    Vlucht * v1 = new Vlucht(&v, &u, 190);
    Vlucht * v2 = new Vlucht(&v, &w, 430);

    n.connections.push_back(n1);
    n.connections.push_back(n2);
    n.connections.push_back(n3);
    o.connections.push_back(o1);
    p.connections.push_back(p1);
    p.connections.push_back(p2);
    q.connections.push_back(q1);
    q.connections.push_back(q2);
    r.connections.push_back(r1);
    s.connections.push_back(s1);
    t.connections.push_back(t1);
    u.connections.push_back(u1);
    v.connections.push_back(v1);
    v.connections.push_back(v2);

    Graaf graaf3 = Graaf(
        {&n, &o, &p, &q, &r, &s, &t, &u, &v, &w},
        {n1, n2, n3, o1, p1, p2, q1, q2, r1, s1, t1, u1, v1, v2}
    );

    std::vector<Station*> kortsteVluchtRoute = graaf3.dijkstra(graaf3, &n, &w);

    //printen van kortste vluchtroute
    std::cout << "Kortste vluchtroute van New York naar Wellington: " << std::endl;
    for(int i = 0; i < kortsteVluchtRoute.size()-1; i++){
        Stap* stap = graaf3.getConnection(kortsteVluchtRoute[i], kortsteVluchtRoute[i+1]);
        std::cout << *stap;
    }
    std::cout << "Totale reistijd: " << w.afstandTotBron/60 << " uur en " << w.afstandTotBron%60 << " minuten";

}