#ifndef rshell_h
#define rshell_h

class RShellBase {
	private:
	public:
		// Constructors
		RShellBase() { };
		
		// Pure Virtual Functions
		virtual void execute() = 0;
		virtual void parse() = 0;
};

#endif