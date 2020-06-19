#pragma once



template<typename Key, typename Value>
void ReleaseMap(std::map<Key, Value *> & map)
{
	std::map<Key, Value*>::iterator iter = map.begin();
	for( ; iter != map.end(); ++iter)
	{
		PmDelete(iter->second);
	}
	map.clear();
}



namespace MemoryUtil
{
	class Run
	{
	public:
		Run() = default;

		~Run()
		{
			ReleaseMap(m_map);
		}

		class Record
		{
		public:
			std::string m_strLogOrg;

			int m_iCount;

			Record(const std::string& str):
			m_iCount(1),
			m_strLogOrg(str)
			{
				
			}
		};


	public:

		void AddLine(const std::string& str);

		void Output(const std::string& strNewLog);

	private:
		std::map<std::string, Record*> m_map;
	};

} // namespace MemoryUtil