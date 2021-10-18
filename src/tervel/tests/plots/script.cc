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
	std::string plot_command;

	std::string executable("../executables/benchmark.x");
	std::string test_size;
	std::string data_structure;
	std::string condition;

	condition.append(" 0");
	test_size.append(" 6");

	//Test QStack
	data_structure.append(" 6");

	command.clear();
	command.append(executable);
	command.append(test_size);
	command.append(data_structure);
	command.append(condition);
	system(command.c_str());

	plot_command.append("gnuplot -e \"outputname='qstack.png'\" plotgraphs.p");
	system(plot_command.c_str());

	//Test QQueue
	data_structure.clear();
	data_structure.append(" 7");
	
	command.clear();
	command.append(executable);
	command.append(test_size);
	command.append(data_structure);
	command.append(condition);
	system(command.c_str());

	plot_command.clear();
	plot_command.append("gnuplot -e \"outputname='qqueue.png'\" plotgraphs.p");
	system(plot_command.c_str());

	return 0; 
}
