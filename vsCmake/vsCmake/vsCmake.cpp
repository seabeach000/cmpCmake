﻿// vsCmake.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

#if defined(_MSC_VER)
#pragma warning(disable : 4244)
#pragma warning(disable : 4603)
#pragma warning(disable : 4996)
#endif

extern "C" {
#define __STDC_CONSTANT_MACROS
#define __STDC_LIMIT_MACROS
#include <libavdevice/avdevice.h>
#include <libavfilter/avfilter.h>
#include <libavformat/avformat.h>
#include <libavutil/avutil.h>
}

#include <json/json.h>
#include <fstream>
#include <cassert>

int main()
{
	avfilter_register_all();
	av_register_all();
	avformat_network_init();
	avcodec_register_all();
	avdevice_register_all();

	// mpegts demuxer does not seek acture with binary search.
	const auto ts_demuxer = av_find_input_format("mpegts");
	ts_demuxer->flags = AVFMT_SHOW_IDS | AVFMT_TS_DISCONT | AVFMT_NOBINSEARCH | AVFMT_GENERIC_INDEX;

	std::ifstream ifs;
	ifs.open("testjson.json");
	assert(ifs.is_open());

	Json::Reader reader;
	Json::Value root;
	if (!reader.parse(ifs,root,false))
	{
		return -1;
	}
	std::string name = root["name"].asString();
	int age = root["age"].asInt();
	std::cout << name << std::endl;
	std::cout << age << std::endl;


    std::cout << "Hello World!\n";
	system("pause");
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
