// Compute  and print mean grades for multiple students

#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <vector>

using std::cin;        using std::setprecision;
using std::cout;       using std::string;
using std::endl;       using std::streamsize;
using std::vector;

int main()
{
	double num_grades = 4; 
	vector<string> students;
	vector<double> mean_scores;
	string student_name;
	double score, total_score, mean_score;
	typedef vector<double>::size_type vec_sz;

	// ask for and read each student's name
	cout << "Enter student's name: ";
	while (cin >> student_name) {
		students.push_back(student_name);
		cout << "Enter " << num_grades << " homework grades: " << endl;

		// read and calculate total score
		score = 0;
		total_score = 0;
		for (int i = 0; i != num_grades; ++i) {
			cin >> score;
			total_score += score;
		}

		// compute mean score for student
		mean_score = total_score / num_grades;
		mean_scores.push_back(mean_score);

		cout << "Enter another student's name "
				"or end-of-file: ";
	}
	cout << endl << endl;

	// write the result
	vec_sz num_students = students.size();
	streamsize prec = cout.precision();
	for (vec_sz i = 0; i != num_students; ++i) {
		cout << "Student: " << students[i] << endl;
		cout << "Mean score: " << setprecision(3) 
		     << mean_scores[i] << setprecision(prec) << endl;
		cout << endl;
    }

	return 0;
}