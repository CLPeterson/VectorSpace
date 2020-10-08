#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <chrono>

FILE *pfile;

int main(int argc,char* argv[]) 
{ 
    auto start = std::chrono::high_resolution_clock::now();

	system("[ -f ../output.txt ] && rm ../output.txt");
	system("[ -f output.txt ] && rm output.txt");

	std::string command;

	std::string executable("../executables/benchmark.x");
	std::string test_size;
	std::string data_structure;
	std::string condition;
	
	//for(unsigned int k = 0; k < 4; k++)
	for(unsigned int k = 0; k < 1; k++)
	{	
		condition.clear();
		if (k == 0)
		{
			condition.append(" 0");
		} else if (k == 1)
		{
			condition.append(" 1");
		} else if (k == 2)
		{
			condition.append(" 2");
		} else if (k == 3)
		{
			condition.append(" 3");
		}		

		for(unsigned int i = 0; i < 4; i++)
		{
			test_size.clear();
			if (i == 0)
			{
				test_size.append(" 10");
			} else if (i == 1)
			{
				test_size.append(" 100");
			} else if (i == 2)
			{
				test_size.append(" 1000");
			} else if (i == 3)
			{
				test_size.append(" 10000");
			}
			
			for(unsigned int j = 0; j < 6; j++)
			{
				data_structure.clear();
				if(j == 0)
				{
					data_structure.append(" 0");
				} else if (j == 1)
				{
					data_structure.append(" 1");
				} else if (j == 2)
				{
					data_structure.append(" 2");
				} else if (j == 3)
				{
					data_structure.append(" 3");
				} else if (j == 4)
				{
					data_structure.append(" 4");
				} else if (j == 5)
				{
					data_structure.append(" 5");
				}
				command.clear();
				command.append(executable);
				command.append(test_size);
				command.append(data_structure);
				command.append(condition);
				system(command.c_str());
				//printf("%s\n", command.c_str());

			}
			pfile = fopen("output.txt", "a");
			fprintf(pfile, "\n\n\n\n\n");
			fclose(pfile);

		}
	}
	
	auto end = std::chrono::high_resolution_clock::now();
	auto elapsed_time = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
	double elapsed_time_double = elapsed_time.count()*0.000000001;

	printf("Duration = %.7f seconds\n", elapsed_time_double);	

	return 0; 
}
