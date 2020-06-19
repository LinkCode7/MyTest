#include "stdafx.h"
#include "Vietnam.h"
#include <boost/program_options.hpp>


using namespace std;
namespace po = boost::program_options;


namespace uh
{
	typedef std::basic_string<TCHAR> tstring;

	template<class T>
	boost::program_options::typed_value<T, TCHAR>* tvalue(T* v)
	{
		return new boost::program_options::typed_value<T, TCHAR>(v);
	}
}



/**
* @brief �K�v�ȃI�v�V������񂪂��邩���`�F�b�N����
* @param vm [in] ������map
* @param option [in] �I�v�V��������
* @param desctiption [in] �I�v�V�����̋L�q
* @retval true �K�v�ȃI�v�V��������
* @retval false �K�v�ȃI�v�V�����Ȃ�
*/
bool check_required_option(const po::variables_map& vm, LPCSTR option, LPCSTR desctiption)
{
	if (vm.count(option) == 0) {
		std::cerr << desctiption << "�����ݒ�ł��B" << std::endl;
		return false;
	}
	return true;
}















// --in_db D:\data\02_���f�[�^\cutData_Vietmap --log D:\Env\Log\log.txt --out_db D:\Env\Data\dione_template_170606.gdb --site
int __main(int argc, _TCHAR* argv[])
{
	po::options_description desc("Allowed options");

	const char * const k_in_db = "in_db";
	const char * const k_log = "log";
	const char * const k_out_db = "out_db";
	const char * const k_mesh_db = "mesh_db";

	const char * const k_site = "site";
	const char * const k_building = "building";
	const char * const k_admin = "admin";
	const char * const k_hnp = "hnp";
	const char * const k_road = "road";
	const char * const k_poi = "poi";

	const char * const k_in_poi_db_date = "in_poi_db_date";
	const char * const k_poi_code = "in_poi_code";
	const char * const k_chainmastername_code = "in_chainmaster_code";
	const char * const k_adminid_list = "in_adminid_list";

	// �R�}���h���C����������
	Arguments args;
	desc.add_options()
		(k_in_db, uh::tvalue<uh::tstring>(&args.in_db), "[�K�{]�C���v�b�gDB")
		(k_log, uh::tvalue<uh::tstring>(&args.log), "[�K�{]���O")
		(k_out_db, uh::tvalue<uh::tstring>(&args.out_db), "[�K�{]�A�E�g�v�b�gDB")
		(k_mesh_db, uh::tvalue<uh::tstring>(&args.mesh_db), "[���H�ϊ����g�p]���b�V��DB")
		(k_poi_code, uh::tvalue<uh::tstring>(&args.poi_code), "[�K�{]poi�R�[�h�t�@�C��")
		(k_chainmastername_code, uh::tvalue<uh::tstring>(&args.chainmaster_code), "[�K�{]chainmaster�R�[�h�t�@�C��")
		(k_adminid_list, uh::tvalue<uh::tstring>(&args.adminid_list), "[�K�{]adminid list�t�@�C��")

		(k_site, "�w�i�|���S���ϊ����[�h")
		(k_building, "�����ϊ����[�h")
		(k_admin, "�s���E�ϊ����[�h")
		(k_road, "���H�ϊ����[�h")
		(k_poi, "POI�ϊ����[�h")
		(k_hnp, "�n�E�X�i���o�[�|�C���g")

		(k_in_poi_db_date, uh::tvalue<uh::tstring>(&args.in_poi_db_date), "�C���v�b�gDB�쐬����")
		;

	if (argc == 1) {
		cerr << "�R�}���h���C�������ɖ�肪����܂�" << endl;
		return 1;
	}

	// argc, argv ����͂��āA���ʂ�vm�Ɋi�[
	po::variables_map vm;
	store(parse_command_line(argc, argv, desc), vm);
	notify(vm);

	// �K�{�p�����[�^�`�F�b�N
	bool bMust = true;

	bMust &= check_required_option(vm, k_in_db, "[�K�{]�C���v�b�gDB");
	bMust &= check_required_option(vm, k_log, "[�K�{]���O");
	bMust &= check_required_option(vm, k_out_db, "[�K�{]�A�E�g�v�b�gPGDB");

	// �p�����[�^������ł͂Ȃ��ꍇ�́A�I�v�V�����\�����ďI��
	if (!bMust) {
		std::cerr << "Vietmap�f�[�^��PGDB�ϊ��c�[��" << std::endl;
		std::cerr << desc << std::endl;
		return 1;
	}

	if (vm.count(k_site) != 0) { args.site = true; }
	if (vm.count(k_building) != 0) { args.building = true; }
	if (vm.count(k_admin) != 0) { args.admin = true; }
	if (vm.count(k_road) != 0) { args.road = true; }
	if (vm.count(k_poi) != 0) { args.poi = true; }
	if (vm.count(k_hnp) != 0) { args.hnp = true; }

	// ������
	CConvertVietmapSiNDY_Vietnam app(args);
	if (app.execute()) 
	{
		cerr << "����I��" << endl;
		return 0;
	}
	else 
	{
		cerr << "�ُ�I��" << endl;
		return 1;
	}
}