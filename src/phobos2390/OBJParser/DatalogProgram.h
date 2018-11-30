#pragma once

#include <vector>
#include <set>

using namespace std;

namespace Datalog
{
	class Identifier
	{
	private:
		string name;
	public:
		Identifier(const string&);
		string getName() const;
		string toString() const;
	};

	class Parameter
	{
	private:
		string name;
		bool identifier;
	public:
		Parameter(const string&, const bool& identifier);
		string getName()const;
		bool isIdentifier()const;
		string toString()const;
	};

	class Predicate
	{
	private:
		Identifier predicateIdentifier;
		vector<Parameter> parameterList;
	public:
		Predicate(const Identifier&, const vector<Parameter>&);
		Identifier getIdentifier() const;
		Parameter operator[](const int&) const;
		int numberOfParameters() const;
		string toString() const;
	};

	class Scheme
	{
	private:
		Predicate schemePredicate;
	public:
		Scheme(const Predicate&);
		Predicate getPredicate() const;
		string toString() const;
	};

	class Rule
	{
	private:
		Predicate initialPredicate;
		vector<Predicate> followingPredicates;
	public:
		Rule(const Predicate&, const vector<Predicate>&);
		Predicate getPredicate()const;
		Predicate operator[](const int&)const;
		string toString()const;
	};

	class Fact
	{
	private:
		Predicate factPredicate;
	public:
		Fact(const Predicate&);
		Predicate getPredicate()const;
		string toString()const;
	};

	class Query
	{
	private:
		Predicate queryPredicate;
	public:
		Query(const Predicate&);
		Predicate getPredicate()const;
		string toString()const;
	};

	class Program
	{
	private:
		vector<Scheme>	programSchemes;
		vector<Rule>	programRules;
		vector<Fact>	programFacts;
		vector<Query>	programQueries;
		set<string>	programDomain;
	public:
		void newScheme(const Predicate&);
		void newRule(const Predicate&, const vector<Predicate>&);
		void newFact(const Predicate&);
		void newQuery(const Predicate&);
		void newDomain(const string&);
		vector<Scheme> getProgramSchemes() const;
		vector<Rule> getProgramRules() const;
		vector<Fact> getProgramFacts() const;
		vector<Query> getProgramQueries() const;
		set<string> getProgramDomain() const;
		string toString() const;
	};
}