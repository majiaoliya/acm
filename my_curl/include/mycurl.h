
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <curl/curl.h>
#include <curl/easy.h>

FILE *fp;//定义FILE类型指针

//这个函数是为了符合CURLOPT_WRITEFUNCTION而构造的
//完成数据保存功能
int finish_len = 0;
size_t write_data(void *ptr, size_t size, size_t nmemb, void *stream)
{
	int written=0;
	written= fwrite(ptr, size, nmemb, (FILE*)stream);
	finish_len += written;
	return written;
}

CURL *curl;
CURLcode res;

int buf_len = 1024*1024*10; //缓冲区大小的长度默认10m
char* HttpBuf = new char[buf_len];

inline void reset_buf_len(int len) {
	free(HttpBuf);
	HttpBuf = new char[len];
}

int read_img(const char* url_str, const char* file_name) { //下载一张图片
	FILE* file = fopen(file_name, "wb");
	curl_easy_setopt(curl, CURLOPT_URL, url_str);
	curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void*)file);
	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
	int res = curl_easy_perform(curl);
	long retcode = 0;
//	retcode = curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &retcode);
	curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &retcode);

	printf("接收图片%s的状态码:%ld\n", file_name, retcode);
	finish_len = 0;
	if((res != CURLE_OK) && (res != CURLE_WRITE_ERROR)){
		printf("%s curl error no=%d\n", __FUNCTION__, res);
		printf("error down : %s\n", url_str);
		exit(-1);
	}
	fclose(file);
	return retcode==200;
}

inline void myinit() {
	curl = curl_easy_init();
}

inline void myclean() {
	curl_easy_cleanup(curl);
	free(HttpBuf);
}

//int main(const char *billid)
//{
//	int ret;
//	FILE *file = NULL;
//	const char *qrload="https://i.nyahentai.net/galleries/1368241/2.jpg";
//	file = fopen("2.jpeg", "wb");
//	curl = curl_easy_init();
//	//curl_easy_setopt(curl, CURLOPT_VERBOSE, 0L);
//	curl_easy_setopt(curl, CURLOPT_URL, qrload);
//	curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void*)file);
//	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
//	//curl_easy_setopt(curl, CURLOPT_POST, 1);
//	res = curl_easy_perform(curl);
//	if((res != CURLE_OK) && (res != CURLE_WRITE_ERROR)){
//		printf("%s curl error no=%d\n", __FUNCTION__, res);
//		return -1;
//	}
//	curl_easy_cleanup(curl);
//	fclose(file);
//	return 0;
//
//}


