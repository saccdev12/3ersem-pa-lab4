# Nombre del ejecutable final
TARGET = lab_2

# Compilador y flags
CXX = g++
CXXFLAGS = -Wall -Werror -std=c++11 -I. -Inegocio -Inegocio/datatypes -Ipresentacion

# Buscamos automáticamente todos los archivos .cpp en el proyecto usando comodines
SRCS = main.cpp \
       $(wildcard negocio/*.cpp) \
       $(wildcard negocio/datatypes/*.cpp) \
       $(wildcard presentacion/*.cpp)

# Convertimos la lista de archivos .cpp en sus correspondientes archivos de objeto .o
OBJS = $(SRCS:.cpp=.o)

# Regla por defecto: compila el ejecutable
all: $(TARGET)

# Regla para enlazar los archivos objeto y crear el binario ejecutable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Regla genérica para compilar cualquier archivo .cpp en un .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Regla para limpiar los archivos temporales generados en la compilación
clean:
	rm -f $(OBJS) $(TARGET)

# Evita conflictos si existen archivos llamados 'all' o 'clean'
.PHONY: all clean