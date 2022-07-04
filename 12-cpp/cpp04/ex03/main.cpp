#include <Character.hpp>
#include <Ice.hpp>
#include <Cure.hpp>
#include <MateriaSource.hpp>

int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;

	std::cout << std::endl << std::endl;

	IMateriaSource* mat = new MateriaSource();
	mat->learnMateria(new Ice());
	mat->learnMateria(new Cure());

	ICharacter* lury = new Character("lury");
	ICharacter* brother = new Character("brother");
	lury->use(0, *brother);

	std::cout << std::endl << std::endl;

	AMateria* tmp_mat;
	tmp_mat = mat->createMateria("fire");
	tmp_mat = mat->createMateria("ice");
	lury->equip(tmp_mat);
	tmp_mat = mat->createMateria("ice");
	lury->equip(tmp_mat);
	tmp_mat = mat->createMateria("cure");
	lury->equip(tmp_mat);
	AMateria* del_mat;
	del_mat = mat->createMateria("cure");
	lury->equip(del_mat);
	tmp_mat = mat->createMateria("cure");
	lury->equip(tmp_mat);
	lury->unequip(3);
	tmp_mat = mat->createMateria("cure");
	lury->equip(tmp_mat);
	lury->use(0, *brother);
	lury->use(3, *brother);

	delete del_mat;


	std::cout << std::endl << std::endl;

	Character* cpBrother = new Character("copy");
	tmp_mat = mat->createMateria("cure");
	cpBrother->equip(tmp_mat);

	Character* newBrother = new Character(*cpBrother);
	delete cpBrother;

	newBrother->use(0, *brother);

	std::cout << std::endl << std::endl;

	Character* assingBrother = new Character("assing");
	tmp_mat = mat->createMateria("cure");
	assingBrother->equip(tmp_mat);

	Character newAssingBrother;
	newAssingBrother = *assingBrother;
	delete assingBrother;

	newAssingBrother.use(0, *brother);

	std::cout << std::endl << std::endl;

	delete lury;
	delete brother;
	delete newBrother;
	delete mat;
	return 0;
}
