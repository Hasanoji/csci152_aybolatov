#include "csci152_student.h"
#include <iostream>
using namespace std;

/*
	 * Standard argument constructor -- you must allocate new 
	 * arrays for assignment_scores and quiz_scores, and copy 
	 * over the values from the initializer lists.
	 *
	 * Do not worry about illegal inputs for this assignment
	 */
	csci152_student::csci152_student(
			std::string nm,
			std::initializer_list<unsigned int> assignments,
			std::initializer_list<double> quizzes,
			double final_exam
	) {
		name = nm;
		num_of_assignments = assignments.size();
		num_of_quizzes = quizzes.size();
		assignment_scores = new unsigned int [assignments.size()];
		int i = 0;
		for(auto item : assignments) {
			assignment_scores[i] = item;
			i++;
		}
		quiz_scores = new double [quizzes.size()];
		i = 0;
		for(auto item : quizzes) {
			quiz_scores[i] = item;
			i++;
		}
		final_exam_score = final_exam;
	}

	/*
	 * Copy constructor
	 */
	csci152_student::csci152_student(const csci152_student& other) {
		name = other.name;
		num_of_assignments = other.num_of_assignments;
		assignment_scores = new unsigned int [num_of_assignments];
		for(int i = 0; i < num_of_assignments; ++i) {
			assignment_scores[i] = other.assignment_scores[i];
		}
		num_of_quizzes = other.num_of_quizzes;
		quiz_scores = new double [num_of_quizzes];
		for(int i = 0; i < num_of_quizzes; ++i) {
			quiz_scores[i] = other.quiz_scores[i];
		}
		final_exam_score = other.final_exam_score;
	}

	/*
	 * Copy assignment - be careful to properly dispose of allocated memory for this
	 * before overwriting with values from other
	 */
	csci152_student& csci152_student::operator=(const csci152_student& other) {
    	name = other.name;
		num_of_assignments = other.num_of_assignments;
		delete assignment_scores;
		assignment_scores = new unsigned int [num_of_assignments];
		for(int i = 0; i < num_of_assignments; ++i) {
			assignment_scores[i] = other.assignment_scores[i];
		}
		num_of_quizzes = other.num_of_quizzes;
		delete quiz_scores;
		quiz_scores = new double [num_of_quizzes];
		for(int i = 0; i < num_of_quizzes; ++i) {
			quiz_scores[i] = other.quiz_scores[i];
		}
		final_exam_score = other.final_exam_score;
		return *this;
	}

	/*
	 * Name getter
	 */
	std::string csci152_student::get_name() const {
		return name;
	}

	/*
	 * Name setter
	 */
	void csci152_student::change_name(std::string new_name) {
		name = new_name;
	}

	/*
	 * Calculates the total assignment percentage between 0.0 and 100.0.
	 * Although individual assignment scores have integer values, the 
	 * final percentage should be a floating-point number
	 */
	double csci152_student::calculate_assignment_perc() const {
		double sum = 0;
		for(int i = 0; i < num_of_assignments; ++i) {
			sum += assignment_scores[i];
		}
		return (sum / num_of_assignments);
	}

	/*
	 * Calculates the total quiz percentage between 0.0 and 100.0, dropping
	 * the lowest quiz score.
	 * Note that individual quiz scores are between 0 and 20.0
	 */
	double csci152_student::calculate_quiz_perc() const {
		double sum = 0;
		double mn = 100;
		for(int i = 0; i < num_of_quizzes; ++i) {
			if(quiz_scores[i] < mn) mn = quiz_scores[i];
			sum += quiz_scores[i];
		}
		sum -= mn;
		return ((sum / (num_of_quizzes - 1)) / 0.2);
	}


	/*
	 * Returns the value stored in final_exam_score
	 */
	double csci152_student::get_final_exam_perc() const {
		return final_exam_score;
	}

	/*
	 * Calculates the total course grade as a percent, using the weighting from
	 * the syllabus
	 */
	double csci152_student::calculate_course_perc() const {
		return (calculate_assignment_perc() * 0.25 + calculate_quiz_perc() * 0.45 + get_final_exam_perc() * 0.3);
	}

	/*
	 * Destructor - don't forget you need to delete anything you explicitly allocated
	 */
	csci152_student::~csci152_student() {
		delete assignment_scores;
		delete quiz_scores;
	}