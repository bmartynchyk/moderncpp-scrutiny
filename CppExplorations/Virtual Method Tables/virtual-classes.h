#pragma once

#include <iostream>

struct Person {
	Person(std::string const& nm, int age): name_(nm), age_(age) { }

	virtual std::string name() const { return name_; };
	virtual std::string occupation() const = 0;
	virtual ~Person() = default;

private:
	std::string name_;
	int age_;
};

struct Teacher : Person {
	//Person::Person();
	Teacher(std::string const& nm, int age, std::string const& crs): 
		Person(nm, age), course_(crs) {
		std::cout << name() << std::endl;
	}

	virtual std::string occupation() const override { return "teacher"; }
	virtual std::string course() const { return course_; }

private:
	std::string course_;
};

struct Professor : Teacher {
	//Teacher::Teacher();
	Professor(std::string const& nm, int age, std::string const& crs, 
		std::string const& thesis): Teacher(nm, age, crs), thesis_(thesis) {
	}

	virtual std::string name() const override { return "Prof. " + Person::name(); }
	virtual std::string occupation() const override { return "Professor"; }
	virtual std::string thesis() const { return thesis_; }

private:
	std::string thesis_;
};



// Override - need to understand if you override something or not.
struct Base {
	virtual void baseFunc1() { std::cout << "Base.baseFunc1();\n"; }
	void baseFunc2() { std::cout << "Base.baseFunc2();\n"; }
};

struct Derived : Base {
	virtual void baseFunc1() override { std::cout << "Derived.baseFunc2();\n"; }
	virtual void baseFunc2() /*override*/ { std::cout << "Derived.baseFunc2();\n"; }
};