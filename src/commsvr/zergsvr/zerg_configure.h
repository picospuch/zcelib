#ifndef ZERG_SERVER_CONFIG_H_
#define ZERG_SERVER_CONFIG_H_

/****************************************************************************************************
class  ZERG_SERVICES_INFO
****************************************************************************************************/
struct ZERG_SERVICES_INFO
{
public:
    ZERG_SERVICES_INFO();
    ~ZERG_SERVICES_INFO();

    //
    SERVICES_ID        zerg_svc_info_;

    //
    ZCE_Sockaddr_In    zerg_ip_addr_;

};


struct ZERG_CONFIG
{
public:

    //����
    static const size_t MAX_SELF_SERVICES_ID = 4;

public:
    //
    ZERG_SERVICES_INFO  svc_info_ary_[MAX_SELF_SERVICES_ID];


    //��������ü���
    Services_Table_Config  services_info_cfg_;


    //ͳ���ļ�
    std::string zerg_stat_file_;

    //ZERG�ı����Ƿ�ʹ��
    bool zerg_insurance_;


    // �������ӵķ���BUFFER���������FRAME�ĸ��� Ĭ��32���������ٶ������ϴ�ĺ�˷���������Ĵ�һЩ, ĿǰDB��256������ȫ����32
    uint32_t accept_send_buf_size_; 
    // ÿ��tcp���ӵķ��Ͷ��г���
    uint32_t connect_send_deque_size; 

    // #��CONNECT���յ�����,��Сʱ��,0-50��������������>0,����15-60������
    uint32_t connect_timeout_; 
    // RECEIVEһ�����ݵĳ�ʱʱ��,Ϊ0��ʾ������,�������ҵ�����߼��ж�һ��
    uint32_t recv_timeout_; 

    // �Ƿ���Ϊ����������
    uint8_t is_proxy_; 
    // #������ӵķ��������� ##ǰ��128000�����1024
    uint32_t max_accept_svr_;
    // #��һ�����������ظ����Է��͵Ĵ���
    uint8_t retry_error_; 

    // ���չܵ�����, Ĭ��50M
    uint32_t recv_pipe_len_;
    // ���͹ܵ�����, Ĭ��50M
    uint32_t send_pipe_len_;
    
};


/****************************************************************************************************
class  Zerg_Server_Config
****************************************************************************************************/
class Zerg_Server_Config :public Server_Config_Base
{

    Zerg_Server_Config();
    ~Zerg_Server_Config();

    //
public:

    /*!
    * @brief      ȡ������Ϣ,ȡ��������Ϣ��, ��Ҫ����������������OK
    * @return     virtual int
    * @param      argc
    * @param      argv
    */
    virtual int initialize(int argc, const char *argv[]);


    //�õ��ļ����ò���
    //����ӿ��е�֣�Ϊ�˰�һЩ������Ϣ�������������֮ǰ�Ͱ���־���Գ�ʼ����
    //virtual int get_file_configure();

    //Dump���õ�������Ϣ
    //void dump_status_info(std::ostringstream &ostr_stream);

    //����SVCINFO�õ�IP��ַ��Ϣ
    int GetServicesIPInfo(const SERVICES_ID &svc_info, ZCE_Sockaddr_In     &ipaddr);

    
    //��ʼ���ⲿ����
    int init_extern_svc();

public:

    //���Ӻ���
    static Zerg_Server_Config *instance();
    //��������ָ�뺯��
    static void clean_instance();



public:

    //
    ZERG_CONFIG  zerg_config_;


    //����ʵ��
    static Zerg_Server_Config  *instance_;



};

#endif //_ZERG_SERVER_CONFIG_H_
