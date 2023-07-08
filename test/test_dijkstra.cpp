#include "include/catch.hpp"
#include "../src/include/Graaf.hpp"
#include "../src/include/Autorit.hpp"
#include "../src/include/Stap.hpp"
#include "../src/include/Station.hpp"
#include "../src/include/StationGreaterThan.hpp"
#include "../src/include/Treinrit.hpp"
#include "../src/include/Vlucht.hpp"

#include <iostream>

TEST_CASE("Connection exists", "Graaf::getConnection"){
    Station a = Station("a");
    Station b = Station("b");
    Autorit * c = new Autorit(&a, &b, 3);
    a.connections.push_back(c);
    Graaf g = Graaf({&a, &b}, {c});

    REQUIRE(g.getConnection(&a, &b) == c);
}

TEST_CASE("Connection does not exist", "Graaf::getConnection"){
    Station a = Station("a");
    Station b = Station("b");
    Autorit * c = new Autorit(&b, &a, 3);
    a.connections.push_back(c);
    Graaf g = Graaf({&a, &b}, {c});

    REQUIRE(g.getConnection(&a, &b) == nullptr);
}

TEST_CASE("Distance from source is zero", "Graaf::getDistance"){
    Station a = Station("a");
    Station b = Station("b");
    Autorit * c = new Autorit(&a, &b, 3);
    a.connections.push_back(c);
    Graaf g = Graaf({&a, &b}, {c});
    std::vector<Station*> path = {&a};
    
    REQUIRE(g.getDistance(path) == 0);
}

TEST_CASE("Distance from source is not zero", "Graaf::getDistance"){
    Station a = Station("a");
    Station b = Station("b");
    Station c = Station("c");
    Autorit * d = new Autorit(&a, &b, 3);
    Autorit * e = new Autorit(&b, &c, 5);
    a.connections.push_back(d);
    b.connections.push_back(e);
    Graaf g = Graaf({&a, &b, &c}, {d, e});
    std::vector<Station*> path = {&a, &b, &c};
    
    REQUIRE(g.getDistance(path) == 8);
}

TEST_CASE("Shortest path is zero", "Graaf::dijkstra"){
    Station a = Station("a");
    Graaf g = Graaf({&a}, {});
    std::vector<Station*> z = g.dijkstra(g, &a, &a);
    
    REQUIRE(g.getDistance(z) == 0);
}

TEST_CASE("Shortest path is not zero", "Graaf::dijkstra"){
    Station a = Station("a");
    Station b = Station("b");
    Station c = Station("c");
    Station d = Station("d");
    Station e = Station("e");
    Station f = Station("f");
    
    Treinrit * a1 = new Treinrit(&a, &b, 7);
    Treinrit * a2 = new Treinrit(&a, &c, 9);
    Treinrit * a3 = new Treinrit(&a, &d, 14);
    Treinrit * b1 = new Treinrit(&b, &c, 10);
    Treinrit * b2 = new Treinrit(&b, &e, 15);
    Treinrit * c1 = new Treinrit(&c, &d, 2);
    Treinrit * c2 = new Treinrit(&c, &e, 11);
    Treinrit * d1 = new Treinrit(&d, &f, 9);
    Treinrit * e1 = new Treinrit(&e, &f, 6);

    a.connections.push_back(a1);
    a.connections.push_back(a2);
    a.connections.push_back(a3);
    b.connections.push_back(b1);
    b.connections.push_back(b2);
    c.connections.push_back(c1);
    c.connections.push_back(c2);
    d.connections.push_back(d1);
    e.connections.push_back(e1);

    Graaf g = Graaf({&a, &b, &c, &d, &e, &f}, {a1, a2, a3, b1, b2, c1, c2, d1, e1});
    std::vector<Station*> foundPath = g.dijkstra(g, &a, &f);
    std::vector<Station*> shortestPath = {&a, &c, &d, &f};

    REQUIRE(shortestPath == foundPath);
}