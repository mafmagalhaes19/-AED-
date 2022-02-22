cmake_minimum_required(VERSION 3.17)
project(AED_G32)

set(CMAKE_CXX_STANDARD 17)

add_executable(AED_G32 FibonacciAirlines/main.cpp Bilhete/Bilhete.h Bilhete/Bilhete.cpp LocaisTransporte/LocaisTransporte.h
        LocaisTransporte/LocaisTransporte.cpp LocaisTransporte/Horario.h
        LocaisTransporte/Horario.cpp Aeroporto/Aeroporto.cpp Aeroporto/Aeroporto.h Bagagem/Bagagem.cpp
        Bagagem/Bagagem.h Bagagem/TransporteBagagem.cpp Servico/Servico.h Servico/Servico.cpp Aviao/Aviao.cpp Aviao/Aviao.h
        Cliente/Cliente.cpp Cliente/Cliente.h Voo/Voo.cpp Voo/Voo.h BST/binaryTree.h BST/binaryTree.h FibonacciAirlines/FibonacciAirlines.cpp FibonacciAirlines/FibonacciAirlines.h Data/Data.cpp Data/Data.h Passageiro/Passageiro.cpp Passageiro/Passageiro.h Menu/Menu.cpp Menu/Menu.h FibonacciAirlines/macros.h FibonacciAirlines/Macros.h)
