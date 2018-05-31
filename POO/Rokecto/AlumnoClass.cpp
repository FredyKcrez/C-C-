typedef struct Alumno
{
	private:
		char:
			name, lastname, id;
		int:
			year, day, month;
		float:
			nota1, nota2, nota3, prom;
			
	public:
		int:
			aprobado = 1, reprobado = 0, seccion;
		char:
			carnet;
} Alumno;

typedef struct Maestro
{
}

