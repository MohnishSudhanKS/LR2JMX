Action()
{

	web_set_sockets_option("SSL_VERSION", "AUTO");

	web_add_auto_header("sec-ch-ua-platform", 
		"\"Windows\"");

	web_add_auto_header("sec-ch-ua", 
		"\"Google Chrome\";v=\"131\", \"Chromium\";v=\"131\", \"Not_A Brand\";v=\"24\"");

	web_add_auto_header("sec-ch-ua-mobile", 
		"?0");

	web_add_header("Sec-Fetch-Site", 
		"none");

	web_add_header("Sec-Fetch-Mode", 
		"navigate");

	web_add_header("Sec-Fetch-Dest", 
		"document");

	web_add_header("Sec-Fetch-User", 
		"?1");

	web_add_header("Upgrade-Insecure-Requests", 
		"1");

	web_url("www.demoblaze.com", 
		"URL=https://www.demoblaze.com/", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTTP", 
		LAST);

	web_add_header("Sec-Fetch-Site", 
		"same-origin");

	web_add_header("Sec-Fetch-Mode", 
		"no-cors");

	web_add_header("Sec-Fetch-Dest", 
		"style");

	web_concurrent_start(NULL);

	web_url("video-js.min.css", 
		"URL=https://www.demoblaze.com/node_modules/video.js/dist/video-js.min.css", 
		"Resource=1", 
		"RecContentType=text/css", 
		"Referer=https://www.demoblaze.com/", 
		"Snapshot=t2.inf", 
		LAST);

	web_add_header("Sec-Fetch-Site", 
		"same-origin");

	web_add_header("Sec-Fetch-Mode", 
		"no-cors");

	web_add_header("Sec-Fetch-Dest", 
		"style");

	web_url("bootstrap.min.css", 
		"URL=https://www.demoblaze.com/node_modules/bootstrap/dist/css/bootstrap.min.css", 
		"Resource=1", 
		"RecContentType=text/css", 
		"Referer=https://www.demoblaze.com/", 
		"Snapshot=t3.inf", 
		LAST);

	web_add_header("Sec-Fetch-Site", 
		"same-origin");

	web_add_header("Sec-Fetch-Mode", 
		"no-cors");

	web_add_header("Sec-Fetch-Dest", 
		"style");

	web_url("latofonts.css", 
		"URL=https://www.demoblaze.com/css/latofonts.css", 
		"Resource=1", 
		"RecContentType=text/css", 
		"Referer=https://www.demoblaze.com/", 
		"Snapshot=t5.inf", 
		LAST);

	web_add_header("Sec-Fetch-Site", 
		"same-origin");

	web_add_header("Sec-Fetch-Mode", 
		"no-cors");

	web_add_header("Sec-Fetch-Dest", 
		"script");

	web_url("jquery.min.js", 
		"URL=https://www.demoblaze.com/node_modules/jquery/dist/jquery.min.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=https://www.demoblaze.com/", 
		"Snapshot=t6.inf", 
		LAST);

	web_add_header("Sec-Fetch-Site", 
		"same-origin");

	web_add_header("Sec-Fetch-Mode", 
		"no-cors");

	web_add_header("Sec-Fetch-Dest", 
		"style");

	web_url("latostyle.css", 
		"URL=https://www.demoblaze.com/css/latostyle.css", 
		"Resource=1", 
		"RecContentType=text/css", 
		"Referer=https://www.demoblaze.com/", 
		"Snapshot=t7.inf", 
		LAST);

	web_add_header("Sec-Fetch-Site", 
		"same-origin");

	web_add_header("Sec-Fetch-Mode", 
		"no-cors");

	web_add_header("Sec-Fetch-Dest", 
		"image");

	web_url("Samsung1.jpg", 
		"URL=https://www.demoblaze.com/Samsung1.jpg", 
		"Resource=1", 
		"RecContentType=image/jpeg", 
		"Referer=https://www.demoblaze.com/", 
		"Snapshot=t8.inf", 
		LAST);

	web_add_header("Sec-Fetch-Site", 
		"same-origin");

	web_add_header("Sec-Fetch-Mode", 
		"no-cors");

	web_add_header("Sec-Fetch-Dest", 
		"image");

	web_url("nexus1.jpg", 
		"URL=https://www.demoblaze.com/nexus1.jpg", 
		"Resource=1", 
		"RecContentType=image/jpeg", 
		"Referer=https://www.demoblaze.com/", 
		"Snapshot=t9.inf", 
		LAST);

	web_add_header("Sec-Fetch-Site", 
		"same-origin");

	web_add_header("Sec-Fetch-Mode", 
		"no-cors");

	web_add_header("Sec-Fetch-Dest", 
		"image");

	web_url("iphone1.jpg", 
		"URL=https://www.demoblaze.com/iphone1.jpg", 
		"Resource=1", 
		"RecContentType=image/jpeg", 
		"Referer=https://www.demoblaze.com/", 
		"Snapshot=t10.inf", 
		LAST);

	web_add_header("Sec-Fetch-Site", 
		"same-origin");

	web_add_header("Sec-Fetch-Mode", 
		"no-cors");

	web_add_header("Sec-Fetch-Dest", 
		"script");

	web_url("video.min.js", 
		"URL=https://www.demoblaze.com/node_modules/video.js/dist/video.min.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=https://www.demoblaze.com/", 
		"Snapshot=t11.inf", 
		LAST);

	web_add_header("Sec-Fetch-Site", 
		"same-origin");

	web_add_header("Sec-Fetch-Mode", 
		"no-cors");

	web_add_header("Sec-Fetch-Dest", 
		"script");

	web_url("videojs-contrib-hls.min.js", 
		"URL=https://www.demoblaze.com/node_modules/videojs-contrib-hls/dist/videojs-contrib-hls.min.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=https://www.demoblaze.com/", 
		"Snapshot=t12.inf", 
		LAST);

	web_add_header("Sec-Fetch-Site", 
		"same-origin");

	web_add_header("Sec-Fetch-Mode", 
		"no-cors");

	web_add_header("Sec-Fetch-Dest", 
		"script");

	web_url("tether.min.js", 
		"URL=https://www.demoblaze.com/node_modules/tether/dist/js/tether.min.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=https://www.demoblaze.com/", 
		"Snapshot=t13.inf", 
		LAST);

	web_add_header("Sec-Fetch-Site", 
		"same-origin");

	web_add_header("Sec-Fetch-Mode", 
		"no-cors");

	web_add_header("Sec-Fetch-Dest", 
		"image");

	web_url("bm.png", 
		"URL=https://www.demoblaze.com/bm.png", 
		"Resource=1", 
		"RecContentType=image/png", 
		"Referer=https://www.demoblaze.com/", 
		"Snapshot=t14.inf", 
		LAST);

	web_add_header("Sec-Fetch-Site", 
		"same-origin");

	web_add_header("Sec-Fetch-Mode", 
		"no-cors");

	web_add_header("Sec-Fetch-Dest", 
		"script");

	web_url("bootstrap.min.js", 
		"URL=https://www.demoblaze.com/node_modules/bootstrap/dist/js/bootstrap.min.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=https://www.demoblaze.com/", 
		"Snapshot=t16.inf", 
		LAST);

	web_add_header("Sec-Fetch-Site", 
		"same-origin");

	web_add_header("Sec-Fetch-Mode", 
		"no-cors");

	web_add_header("Sec-Fetch-Dest", 
		"script");

	web_url("index.js", 
		"URL=https://www.demoblaze.com/js/index.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=https://www.demoblaze.com/", 
		"Snapshot=t17.inf", 
		LAST);

	web_add_header("Sec-Fetch-Site", 
		"same-origin");

	web_add_header("Sec-Fetch-Mode", 
		"no-cors");

	web_add_header("Sec-Fetch-Dest", 
		"image");

	web_url("favicon.ico", 
		"URL=https://www.demoblaze.com/favicon.ico", 
		"Resource=1", 
		"RecContentType=image/vnd.microsoft.icon", 
		"Referer=https://www.demoblaze.com/", 
		"Snapshot=t18.inf", 
		LAST);

	web_concurrent_end(NULL);

	web_add_header("Sec-Fetch-Site", 
		"same-origin");

	web_add_header("Sec-Fetch-Mode", 
		"no-cors");

	web_add_header("Sec-Fetch-Dest", 
		"image");

	web_url("front.jpg", 
		"URL=https://www.demoblaze.com/imgs/front.jpg", 
		"Resource=1", 
		"RecContentType=image/jpeg", 
		"Referer=https://www.demoblaze.com/", 
		"Snapshot=t4.inf", 
		LAST);

	web_add_header("Origin", 
		"https://www.demoblaze.com");

	web_add_header("Sec-Fetch-Site", 
		"same-origin");

	web_add_header("Sec-Fetch-Mode", 
		"cors");

	web_add_header("Sec-Fetch-Dest", 
		"font");

	web_url("Lato-Regular.woff2", 
		"URL=https://www.demoblaze.com/css/fonts/Lato-Regular.woff2", 
		"Resource=1", 
		"RecContentType=application/octet-stream", 
		"Referer=https://www.demoblaze.com/css/latofonts.css", 
		"Snapshot=t15.inf", 
		LAST);

	web_add_header("Sec-Fetch-Site", 
		"same-origin");

	web_add_auto_header("Sec-Fetch-Mode", 
		"cors");

	web_add_auto_header("Sec-Fetch-Dest", 
		"empty");

	web_add_header("X-Requested-With", 
		"XMLHttpRequest");

	web_url("config.json", 
		"URL=https://www.demoblaze.com/config.json", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://www.demoblaze.com/", 
		"Snapshot=t19.inf", 
		"Mode=HTTP", 
		LAST);

	web_add_header("Origin", 
		"https://www.demoblaze.com");

	web_add_header("Sec-Fetch-Site", 
		"same-site");

	lr_think_time(4);

	web_url("index.m3u8", 
		"URL=https://hls.demoblaze.com/index.m3u8", 
		"Resource=1", 
		"RecContentType=binary/octet-stream", 
		"Referer=https://www.demoblaze.com/", 
		"Snapshot=t20.inf", 
		LAST);

	web_add_auto_header("Origin", 
		"https://www.demoblaze.com");

	web_add_auto_header("Sec-Fetch-Site", 
		"same-site");

	web_url("entries", 
		"URL=https://api.demoblaze.com/entries", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://www.demoblaze.com/", 
		"Snapshot=t21.inf", 
		"Mode=HTTP", 
		LAST);

	web_concurrent_start(NULL);

	web_url("about_demo_hls_600k.m3u8", 
		"URL=https://hls.demoblaze.com/about_demo_hls_600k.m3u8", 
		"Resource=1", 
		"RecContentType=binary/octet-stream", 
		"Referer=https://www.demoblaze.com/", 
		"Snapshot=t22.inf", 
		LAST);

	web_url("about_demo_hls_600k00000.ts", 
		"URL=https://hls.demoblaze.com/about_demo_hls_600k00000.ts", 
		"Resource=1", 
		"RecContentType=text/plain", 
		"Referer=https://www.demoblaze.com/", 
		"Snapshot=t23.inf", 
		LAST);

	web_url("Lumia_1520.jpg", 
		"URL=https://www.demoblaze.com/imgs/Lumia_1520.jpg", 
		"Resource=1", 
		"RecContentType=image/jpeg", 
		"Referer=https://www.demoblaze.com/", 
		"Snapshot=t24.inf", 
		LAST);

	web_url("galaxy_s6.jpg", 
		"URL=https://www.demoblaze.com/imgs/galaxy_s6.jpg", 
		"Resource=1", 
		"RecContentType=image/jpeg", 
		"Referer=https://www.demoblaze.com/", 
		"Snapshot=t25.inf", 
		LAST);

	web_url("xperia_z5.jpg", 
		"URL=https://www.demoblaze.com/imgs/xperia_z5.jpg", 
		"Resource=1", 
		"RecContentType=image/jpeg", 
		"Referer=https://www.demoblaze.com/", 
		"Snapshot=t26.inf", 
		LAST);

	web_url("Nexus_6.jpg", 
		"URL=https://www.demoblaze.com/imgs/Nexus_6.jpg", 
		"Resource=1", 
		"RecContentType=image/jpeg", 
		"Referer=https://www.demoblaze.com/", 
		"Snapshot=t27.inf", 
		LAST);

	web_url("sony_vaio_5.jpg", 
		"URL=https://www.demoblaze.com/imgs/sony_vaio_5.jpg", 
		"Resource=1", 
		"RecContentType=image/jpeg", 
		"Referer=https://www.demoblaze.com/", 
		"Snapshot=t28.inf", 
		LAST);

	web_url("iphone_6.jpg", 
		"URL=https://www.demoblaze.com/imgs/iphone_6.jpg", 
		"Resource=1", 
		"RecContentType=image/jpeg", 
		"Referer=https://www.demoblaze.com/", 
		"Snapshot=t29.inf", 
		LAST);

	web_url("HTC_M9.jpg", 
		"URL=https://www.demoblaze.com/imgs/HTC_M9.jpg", 
		"Resource=1", 
		"RecContentType=image/jpeg", 
		"Referer=https://www.demoblaze.com/", 
		"Snapshot=t30.inf", 
		LAST);

	web_concurrent_end(NULL);

	lr_start_transaction("Login");

	web_revert_auto_header("sec-ch-ua");

	web_revert_auto_header("sec-ch-ua-mobile");

	web_revert_auto_header("sec-ch-ua-platform");

	web_add_header("Access-Control-Request-Headers", 
		"content-type");

	web_add_header("Access-Control-Request-Method", 
		"POST");

	lr_think_time(18);

	web_custom_request("login", 
		"URL=https://api.demoblaze.com/login", 
		"Method=OPTIONS", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://www.demoblaze.com/", 
		"Snapshot=t31.inf", 
		"Mode=HTTP", 
		LAST);

	web_add_auto_header("sec-ch-ua", 
		"\"Google Chrome\";v=\"131\", \"Chromium\";v=\"131\", \"Not_A Brand\";v=\"24\"");

	web_add_auto_header("sec-ch-ua-mobile", 
		"?0");

	web_add_auto_header("sec-ch-ua-platform", 
		"\"Windows\"");

	web_custom_request("login_2", 
		"URL=https://api.demoblaze.com/login", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://www.demoblaze.com/", 
		"Snapshot=t32.inf", 
		"Mode=HTTP", 
		"EncType=application/json", 
		"Body={\"username\":\"tomjerry2024\",\"password\":\"MTIzNA==\"}", 
		LAST);

	web_add_cookie("tokenp_=dG9tamVycnkyMDI0MTczNDU5OA==; DOMAIN=www.demoblaze.com");

	web_revert_auto_header("Origin");

	web_add_auto_header("Sec-Fetch-Mode", 
		"navigate");

	web_add_auto_header("Sec-Fetch-Dest", 
		"document");

	web_add_header("Cache-Control", 
		"max-age=0");

	web_add_auto_header("If-None-Match", 
		"\"TTo8pA\"");

	web_add_auto_header("Sec-Fetch-Site", 
		"same-origin");

	web_add_header("Sec-Fetch-User", 
		"?1");

	web_add_header("Upgrade-Insecure-Requests", 
		"1");

	web_url("www.demoblaze.com_2", 
		"URL=https://www.demoblaze.com/", 
		"Resource=0", 
		"Referer=https://www.demoblaze.com/", 
		"Snapshot=t33.inf", 
		"Mode=HTTP", 
		LAST);

	web_add_auto_header("Sec-Fetch-Dest", 
		"style");

	web_add_auto_header("Sec-Fetch-Mode", 
		"no-cors");

	web_url("latofonts.css_2", 
		"URL=https://www.demoblaze.com/css/latofonts.css", 
		"Resource=1", 
		"Referer=https://www.demoblaze.com/", 
		"Snapshot=t34.inf", 
		LAST);

	web_url("bootstrap.min.css_2", 
		"URL=https://www.demoblaze.com/node_modules/bootstrap/dist/css/bootstrap.min.css", 
		"Resource=1", 
		"Referer=https://www.demoblaze.com/", 
		"Snapshot=t35.inf", 
		LAST);

	web_add_auto_header("Sec-Fetch-Dest", 
		"script");

	web_url("jquery.min.js_2", 
		"URL=https://www.demoblaze.com/node_modules/jquery/dist/jquery.min.js", 
		"Resource=1", 
		"Referer=https://www.demoblaze.com/", 
		"Snapshot=t36.inf", 
		LAST);

	web_add_auto_header("Sec-Fetch-Dest", 
		"style");

	web_url("video-js.min.css_2", 
		"URL=https://www.demoblaze.com/node_modules/video.js/dist/video-js.min.css", 
		"Resource=1", 
		"Referer=https://www.demoblaze.com/", 
		"Snapshot=t37.inf", 
		LAST);

	web_url("latostyle.css_2", 
		"URL=https://www.demoblaze.com/css/latostyle.css", 
		"Resource=1", 
		"Referer=https://www.demoblaze.com/", 
		"Snapshot=t38.inf", 
		LAST);

	web_add_auto_header("Sec-Fetch-Dest", 
		"image");

	web_url("Samsung1.jpg_2", 
		"URL=https://www.demoblaze.com/Samsung1.jpg", 
		"Resource=1", 
		"Referer=https://www.demoblaze.com/", 
		"Snapshot=t39.inf", 
		LAST);

	web_url("front.jpg_2", 
		"URL=https://www.demoblaze.com/imgs/front.jpg", 
		"Resource=1", 
		"Referer=https://www.demoblaze.com/", 
		"Snapshot=t40.inf", 
		LAST);

	web_add_auto_header("Sec-Fetch-Dest", 
		"script");

	web_url("video.min.js_2", 
		"URL=https://www.demoblaze.com/node_modules/video.js/dist/video.min.js", 
		"Resource=1", 
		"Referer=https://www.demoblaze.com/", 
		"Snapshot=t41.inf", 
		LAST);

	web_add_auto_header("Sec-Fetch-Dest", 
		"image");

	web_url("iphone1.jpg_2", 
		"URL=https://www.demoblaze.com/iphone1.jpg", 
		"Resource=1", 
		"Referer=https://www.demoblaze.com/", 
		"Snapshot=t42.inf", 
		LAST);

	web_url("nexus1.jpg_2", 
		"URL=https://www.demoblaze.com/nexus1.jpg", 
		"Resource=1", 
		"Referer=https://www.demoblaze.com/", 
		"Snapshot=t43.inf", 
		LAST);

	web_add_auto_header("Sec-Fetch-Dest", 
		"script");

	web_url("videojs-contrib-hls.min.js_2", 
		"URL=https://www.demoblaze.com/node_modules/videojs-contrib-hls/dist/videojs-contrib-hls.min.js", 
		"Resource=1", 
		"Referer=https://www.demoblaze.com/", 
		"Snapshot=t44.inf", 
		LAST);

	web_url("bootstrap.min.js_2", 
		"URL=https://www.demoblaze.com/node_modules/bootstrap/dist/js/bootstrap.min.js", 
		"Resource=1", 
		"Referer=https://www.demoblaze.com/", 
		"Snapshot=t45.inf", 
		LAST);

	web_add_auto_header("Sec-Fetch-Dest", 
		"image");

	web_url("bm.png_2", 
		"URL=https://www.demoblaze.com/bm.png", 
		"Resource=1", 
		"Referer=https://www.demoblaze.com/", 
		"Snapshot=t46.inf", 
		LAST);

	web_add_auto_header("Sec-Fetch-Dest", 
		"script");

	web_url("tether.min.js_2", 
		"URL=https://www.demoblaze.com/node_modules/tether/dist/js/tether.min.js", 
		"Resource=1", 
		"Referer=https://www.demoblaze.com/", 
		"Snapshot=t47.inf", 
		LAST);

	web_url("index.js_2", 
		"URL=https://www.demoblaze.com/js/index.js", 
		"Resource=1", 
		"Referer=https://www.demoblaze.com/", 
		"Snapshot=t48.inf", 
		LAST);

	web_add_header("X-Requested-With", 
		"XMLHttpRequest");

	web_url("config.json_2", 
		"URL=https://www.demoblaze.com/config.json", 
		"Resource=1", 
		"Referer=https://www.demoblaze.com/", 
		"Snapshot=t49.inf", 
		LAST);

	web_add_auto_header("Sec-Fetch-Dest", 
		"image");

	web_url("favicon.ico_2", 
		"URL=https://www.demoblaze.com/favicon.ico", 
		"Resource=1", 
		"Referer=https://www.demoblaze.com/", 
		"Snapshot=t50.inf", 
		LAST);

	web_revert_auto_header("If-None-Match");

	web_revert_auto_header("sec-ch-ua");

	web_revert_auto_header("sec-ch-ua-mobile");

	web_revert_auto_header("sec-ch-ua-platform");

	web_add_header("Access-Control-Request-Headers", 
		"content-type");

	web_add_header("Access-Control-Request-Method", 
		"POST");

	web_add_auto_header("Origin", 
		"https://www.demoblaze.com");

	web_add_auto_header("Sec-Fetch-Dest", 
		"empty");

	web_add_auto_header("Sec-Fetch-Mode", 
		"cors");

	web_add_auto_header("Sec-Fetch-Site", 
		"same-site");

	web_custom_request("check", 
		"URL=https://api.demoblaze.com/check", 
		"Method=OPTIONS", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://www.demoblaze.com/", 
		"Snapshot=t51.inf", 
		"Mode=HTTP", 
		LAST);

	web_add_auto_header("sec-ch-ua", 
		"\"Google Chrome\";v=\"131\", \"Chromium\";v=\"131\", \"Not_A Brand\";v=\"24\"");

	web_add_auto_header("sec-ch-ua-mobile", 
		"?0");

	web_add_auto_header("sec-ch-ua-platform", 
		"\"Windows\"");

	web_url("entries_2", 
		"URL=https://api.demoblaze.com/entries", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://www.demoblaze.com/", 
		"Snapshot=t52.inf", 
		"Mode=HTTP", 
		LAST);

	web_custom_request("check_2", 
		"URL=https://api.demoblaze.com/check", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://www.demoblaze.com/", 
		"Snapshot=t53.inf", 
		"Mode=HTTP", 
		"EncType=application/json", 
		"Body={\"token\":\"dG9tamVycnkyMDI0MTczNDU5OA==\"}", 
		LAST);

	web_add_header("If-None-Match", 
		"\"TTo8pA\"");

	web_concurrent_start(NULL);

	web_url("galaxy_s6.jpg_2", 
		"URL=https://www.demoblaze.com/imgs/galaxy_s6.jpg", 
		"Resource=1", 
		"Referer=https://www.demoblaze.com/", 
		"Snapshot=t54.inf", 
		LAST);

	web_add_header("If-None-Match", 
		"\"TTo8pA\"");

	web_url("Lumia_1520.jpg_2", 
		"URL=https://www.demoblaze.com/imgs/Lumia_1520.jpg", 
		"Resource=1", 
		"Referer=https://www.demoblaze.com/", 
		"Snapshot=t55.inf", 
		LAST);

	web_add_header("If-None-Match", 
		"\"TTo8pA\"");

	web_url("Nexus_6.jpg_2", 
		"URL=https://www.demoblaze.com/imgs/Nexus_6.jpg", 
		"Resource=1", 
		"Referer=https://www.demoblaze.com/", 
		"Snapshot=t56.inf", 
		LAST);

	web_add_header("If-None-Match", 
		"\"TTo8pA\"");

	web_url("iphone_6.jpg_2", 
		"URL=https://www.demoblaze.com/imgs/iphone_6.jpg", 
		"Resource=1", 
		"Referer=https://www.demoblaze.com/", 
		"Snapshot=t57.inf", 
		LAST);

	web_add_header("If-None-Match", 
		"\"TTo8pA\"");

	web_url("sony_vaio_5.jpg_2", 
		"URL=https://www.demoblaze.com/imgs/sony_vaio_5.jpg", 
		"Resource=1", 
		"Referer=https://www.demoblaze.com/", 
		"Snapshot=t58.inf", 
		LAST);

	web_add_header("If-None-Match", 
		"\"TTo8pA\"");

	web_url("xperia_z5.jpg_2", 
		"URL=https://www.demoblaze.com/imgs/xperia_z5.jpg", 
		"Resource=1", 
		"Referer=https://www.demoblaze.com/", 
		"Snapshot=t59.inf", 
		LAST);

	web_add_header("If-None-Match", 
		"\"TTo8pA\"");

	web_url("HTC_M9.jpg_2", 
		"URL=https://www.demoblaze.com/imgs/HTC_M9.jpg", 
		"Resource=1", 
		"Referer=https://www.demoblaze.com/", 
		"Snapshot=t60.inf", 
		LAST);

	web_concurrent_end(NULL);

	lr_end_transaction("Login",LR_AUTO);

	lr_start_transaction("SelectCategory");

	web_revert_auto_header("sec-ch-ua");

	web_revert_auto_header("sec-ch-ua-mobile");

	web_revert_auto_header("sec-ch-ua-platform");

	web_add_header("Access-Control-Request-Headers", 
		"content-type");

	web_add_header("Access-Control-Request-Method", 
		"POST");

	lr_think_time(14);

	web_custom_request("bycat", 
		"URL=https://api.demoblaze.com/bycat", 
		"Method=OPTIONS", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://www.demoblaze.com/", 
		"Snapshot=t61.inf", 
		"Mode=HTTP", 
		LAST);

	web_add_header("sec-ch-ua-platform", 
		"\"Windows\"");

	web_add_header("sec-ch-ua", 
		"\"Google Chrome\";v=\"131\", \"Chromium\";v=\"131\", \"Not_A Brand\";v=\"24\"");

	web_add_header("sec-ch-ua-mobile", 
		"?0");

	web_add_header("If-None-Match", 
		"\"TTo8pA\"");

	web_url("favicon.ico_3", 
		"URL=https://www.demoblaze.com/favicon.ico", 
		"Resource=1", 
		"Referer=https://www.demoblaze.com/", 
		"Snapshot=t62.inf", 
		LAST);

	web_add_auto_header("sec-ch-ua-platform", 
		"\"Windows\"");

	web_add_auto_header("sec-ch-ua", 
		"\"Google Chrome\";v=\"131\", \"Chromium\";v=\"131\", \"Not_A Brand\";v=\"24\"");

	web_add_auto_header("sec-ch-ua-mobile", 
		"?0");

	web_custom_request("bycat_2", 
		"URL=https://api.demoblaze.com/bycat", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://www.demoblaze.com/", 
		"Snapshot=t63.inf", 
		"Mode=HTTP", 
		"EncType=application/json", 
		"Body={\"cat\":\"notebook\"}", 
		LAST);

	web_concurrent_start(NULL);

	web_url("dell.jpg", 
		"URL=https://www.demoblaze.com/imgs/dell.jpg", 
		"Resource=1", 
		"RecContentType=image/jpeg", 
		"Referer=https://www.demoblaze.com/", 
		"Snapshot=t64.inf", 
		LAST);

	web_url("macbook_air.jpg", 
		"URL=https://www.demoblaze.com/imgs/macbook_air.jpg", 
		"Resource=1", 
		"RecContentType=image/jpeg", 
		"Referer=https://www.demoblaze.com/", 
		"Snapshot=t65.inf", 
		LAST);

	web_concurrent_end(NULL);

	lr_end_transaction("SelectCategory",LR_AUTO);

	lr_start_transaction("SelectItems");

	web_revert_auto_header("Origin");

	web_add_auto_header("Sec-Fetch-Mode", 
		"navigate");

	web_add_auto_header("Sec-Fetch-Site", 
		"same-origin");

	web_add_auto_header("Sec-Fetch-Dest", 
		"document");

	web_add_header("Sec-Fetch-User", 
		"?1");

	web_add_header("Upgrade-Insecure-Requests", 
		"1");

	lr_think_time(24);

	web_url("prod.html", 
		"URL=https://www.demoblaze.com/prod.html?idp_=8", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://www.demoblaze.com/", 
		"Snapshot=t66.inf", 
		"Mode=HTTP", 
		LAST);

	web_add_header("If-None-Match", 
		"\"TTo8pA\"");

	web_concurrent_start(NULL);

	web_url("bootstrap.min.css_3", 
		"URL=https://www.demoblaze.com/node_modules/bootstrap/dist/css/bootstrap.min.css", 
		"Resource=1", 
		"Referer=https://www.demoblaze.com/prod.html?idp_=8", 
		"Snapshot=t67.inf", 
		LAST);

	web_add_header("If-None-Match", 
		"\"TTo8pA\"");

	web_url("video-js.min.css_3", 
		"URL=https://www.demoblaze.com/node_modules/video.js/dist/video-js.min.css", 
		"Resource=1", 
		"Referer=https://www.demoblaze.com/prod.html?idp_=8", 
		"Snapshot=t68.inf", 
		LAST);

	web_add_header("If-None-Match", 
		"\"TTo8pA\"");

	web_url("jquery.min.js_3", 
		"URL=https://www.demoblaze.com/node_modules/jquery/dist/jquery.min.js", 
		"Resource=1", 
		"Referer=https://www.demoblaze.com/prod.html?idp_=8", 
		"Snapshot=t69.inf", 
		LAST);

	web_add_header("If-None-Match", 
		"\"TTo8pA\"");

	web_url("latostyle.css_3", 
		"URL=https://www.demoblaze.com/css/latostyle.css", 
		"Resource=1", 
		"Referer=https://www.demoblaze.com/prod.html?idp_=8", 
		"Snapshot=t70.inf", 
		LAST);

	web_add_header("If-None-Match", 
		"\"TTo8pA\"");

	web_url("latofonts.css_3", 
		"URL=https://www.demoblaze.com/css/latofonts.css", 
		"Resource=1", 
		"Referer=https://www.demoblaze.com/prod.html?idp_=8", 
		"Snapshot=t71.inf", 
		LAST);

	web_add_header("If-None-Match", 
		"\"TTo8pA\"");

	web_url("video.min.js_3", 
		"URL=https://www.demoblaze.com/node_modules/video.js/dist/video.min.js", 
		"Resource=1", 
		"Referer=https://www.demoblaze.com/prod.html?idp_=8", 
		"Snapshot=t72.inf", 
		LAST);

	web_add_header("If-None-Match", 
		"\"TTo8pA\"");

	web_url("videojs-contrib-hls.min.js_3", 
		"URL=https://www.demoblaze.com/node_modules/videojs-contrib-hls/dist/videojs-contrib-hls.min.js", 
		"Resource=1", 
		"Referer=https://www.demoblaze.com/prod.html?idp_=8", 
		"Snapshot=t74.inf", 
		LAST);

	web_add_header("If-None-Match", 
		"\"TTo8pA\"");

	web_url("bootstrap.min.js_3", 
		"URL=https://www.demoblaze.com/node_modules/bootstrap/dist/js/bootstrap.min.js", 
		"Resource=1", 
		"Referer=https://www.demoblaze.com/prod.html?idp_=8", 
		"Snapshot=t75.inf", 
		LAST);

	web_url("prod.js", 
		"URL=https://www.demoblaze.com/js/prod.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=https://www.demoblaze.com/prod.html?idp_=8", 
		"Snapshot=t76.inf", 
		LAST);

	web_add_header("If-None-Match", 
		"\"TTo8pA\"");

	web_url("tether.min.js_3", 
		"URL=https://www.demoblaze.com/node_modules/tether/dist/js/tether.min.js", 
		"Resource=1", 
		"Referer=https://www.demoblaze.com/prod.html?idp_=8", 
		"Snapshot=t77.inf", 
		LAST);

	web_add_header("If-None-Match", 
		"\"TTo8pA\"");

	web_url("bm.png_3", 
		"URL=https://www.demoblaze.com/bm.png", 
		"Resource=1", 
		"Referer=https://www.demoblaze.com/prod.html?idp_=8", 
		"Snapshot=t78.inf", 
		LAST);

	web_add_header("If-None-Match", 
		"\"TTo8pA\"");

	web_url("favicon.ico_4", 
		"URL=https://www.demoblaze.com/favicon.ico", 
		"Resource=1", 
		"Referer=https://www.demoblaze.com/prod.html?idp_=8", 
		"Snapshot=t80.inf", 
		LAST);

	web_concurrent_end(NULL);

	web_add_header("If-None-Match", 
		"\"TTo8pA\"");

	web_url("front.jpg_3", 
		"URL=https://www.demoblaze.com/imgs/front.jpg", 
		"Resource=1", 
		"Referer=https://www.demoblaze.com/prod.html?idp_=8", 
		"Snapshot=t73.inf", 
		LAST);

	web_add_header("X-Requested-With", 
		"XMLHttpRequest");

	web_add_header("If-None-Match", 
		"\"TTo8pA\"");

	web_url("config.json_3", 
		"URL=https://www.demoblaze.com/config.json", 
		"Resource=1", 
		"Referer=https://www.demoblaze.com/prod.html?idp_=8", 
		"Snapshot=t79.inf", 
		LAST);

	web_revert_auto_header("sec-ch-ua");

	web_revert_auto_header("sec-ch-ua-mobile");

	web_revert_auto_header("sec-ch-ua-platform");

	web_add_auto_header("Access-Control-Request-Headers", 
		"content-type");

	web_add_auto_header("Access-Control-Request-Method", 
		"POST");

	web_add_auto_header("Origin", 
		"https://www.demoblaze.com");

	web_add_auto_header("Sec-Fetch-Dest", 
		"empty");

	web_add_auto_header("Sec-Fetch-Mode", 
		"cors");

	web_add_auto_header("Sec-Fetch-Site", 
		"same-site");

	web_custom_request("check_3", 
		"URL=https://api.demoblaze.com/check", 
		"Method=OPTIONS", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://www.demoblaze.com/", 
		"Snapshot=t81.inf", 
		"Mode=HTTP", 
		LAST);

	web_custom_request("view", 
		"URL=https://api.demoblaze.com/view", 
		"Method=OPTIONS", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://www.demoblaze.com/", 
		"Snapshot=t82.inf", 
		"Mode=HTTP", 
		LAST);

	web_revert_auto_header("Access-Control-Request-Headers");

	web_revert_auto_header("Access-Control-Request-Method");

	web_add_auto_header("sec-ch-ua", 
		"\"Google Chrome\";v=\"131\", \"Chromium\";v=\"131\", \"Not_A Brand\";v=\"24\"");

	web_add_auto_header("sec-ch-ua-mobile", 
		"?0");

	web_add_auto_header("sec-ch-ua-platform", 
		"\"Windows\"");

	web_custom_request("view_2", 
		"URL=https://api.demoblaze.com/view", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://www.demoblaze.com/", 
		"Snapshot=t83.inf", 
		"Mode=HTTP", 
		"EncType=application/json", 
		"Body={\"id\":\"8\"}", 
		LAST);

	web_custom_request("check_4", 
		"URL=https://api.demoblaze.com/check", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://www.demoblaze.com/", 
		"Snapshot=t84.inf", 
		"Mode=HTTP", 
		"EncType=application/json", 
		"Body={\"token\":\"dG9tamVycnkyMDI0MTczNDU5OA==\"}", 
		LAST);

	web_add_header("If-None-Match", 
		"\"TTo8pA\"");

	web_url("sony_vaio_5.jpg_3", 
		"URL=https://www.demoblaze.com/imgs/sony_vaio_5.jpg", 
		"Resource=1", 
		"Referer=https://www.demoblaze.com/prod.html?idp_=8", 
		"Snapshot=t85.inf", 
		LAST);

	lr_end_transaction("SelectItems",LR_AUTO);

	lr_start_transaction("AddToCart");

	web_revert_auto_header("Origin");

	web_add_auto_header("Sec-Fetch-Mode", 
		"no-cors");

	web_add_auto_header("Sec-Fetch-Site", 
		"same-origin");

	web_add_auto_header("Sec-Fetch-Dest", 
		"image");

	web_add_header("If-None-Match", 
		"\"TTo8pA\"");

	lr_think_time(13);

	web_url("favicon.ico_5", 
		"URL=https://www.demoblaze.com/favicon.ico", 
		"Resource=1", 
		"Referer=https://www.demoblaze.com/prod.html?idp_=8", 
		"Snapshot=t86.inf", 
		LAST);

	web_revert_auto_header("sec-ch-ua");

	web_revert_auto_header("sec-ch-ua-mobile");

	web_revert_auto_header("sec-ch-ua-platform");

	web_add_header("Access-Control-Request-Headers", 
		"content-type");

	web_add_header("Access-Control-Request-Method", 
		"POST");

	web_add_auto_header("Origin", 
		"https://www.demoblaze.com");

	web_add_auto_header("Sec-Fetch-Dest", 
		"empty");

	web_add_auto_header("Sec-Fetch-Mode", 
		"cors");

	web_add_auto_header("Sec-Fetch-Site", 
		"same-site");

	web_custom_request("addtocart", 
		"URL=https://api.demoblaze.com/addtocart", 
		"Method=OPTIONS", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://www.demoblaze.com/", 
		"Snapshot=t87.inf", 
		"Mode=HTTP", 
		LAST);

	web_add_auto_header("sec-ch-ua", 
		"\"Google Chrome\";v=\"131\", \"Chromium\";v=\"131\", \"Not_A Brand\";v=\"24\"");

	web_add_auto_header("sec-ch-ua-mobile", 
		"?0");

	web_add_auto_header("sec-ch-ua-platform", 
		"\"Windows\"");

	web_custom_request("addtocart_2", 
		"URL=https://api.demoblaze.com/addtocart", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://www.demoblaze.com/", 
		"Snapshot=t88.inf", 
		"Mode=HTTP", 
		"EncType=application/json", 
		"Body={\"id\":\"24433116-1728-8553-10d3-c19f5c2cf7c5\",\"cookie\":\"dG9tamVycnkyMDI0MTczNDU5OA==\",\"prod_id\":8,\"flag\":true}", 
		LAST);

	lr_end_transaction("AddToCart",LR_AUTO);

	lr_start_transaction("GoToCart");

	web_revert_auto_header("Origin");

	web_add_auto_header("Sec-Fetch-Mode", 
		"navigate");

	web_add_auto_header("Sec-Fetch-Site", 
		"same-origin");

	web_add_auto_header("Sec-Fetch-Dest", 
		"document");

	web_add_header("Sec-Fetch-User", 
		"?1");

	web_add_header("Upgrade-Insecure-Requests", 
		"1");

	lr_think_time(13);

	web_url("cart.html", 
		"URL=https://www.demoblaze.com/cart.html", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://www.demoblaze.com/prod.html?idp_=8", 
		"Snapshot=t89.inf", 
		"Mode=HTTP", 
		LAST);

	web_concurrent_start(NULL);

	web_url("sweetalert.css", 
		"URL=https://www.demoblaze.com/node_modules/bootstrap-sweetalert/dist/sweetalert.css", 
		"Resource=1", 
		"RecContentType=text/css", 
		"Referer=https://www.demoblaze.com/cart.html", 
		"Snapshot=t90.inf", 
		LAST);

	web_add_header("If-None-Match", 
		"\"TTo8pA\"");

	web_url("bootstrap.min.css_4", 
		"URL=https://www.demoblaze.com/node_modules/bootstrap/dist/css/bootstrap.min.css", 
		"Resource=1", 
		"Referer=https://www.demoblaze.com/cart.html", 
		"Snapshot=t91.inf", 
		LAST);

	web_add_header("If-None-Match", 
		"\"TTo8pA\"");

	web_url("latofonts.css_4", 
		"URL=https://www.demoblaze.com/css/latofonts.css", 
		"Resource=1", 
		"Referer=https://www.demoblaze.com/cart.html", 
		"Snapshot=t92.inf", 
		LAST);

	web_add_header("If-None-Match", 
		"\"TTo8pA\"");

	web_url("video-js.min.css_4", 
		"URL=https://www.demoblaze.com/node_modules/video.js/dist/video-js.min.css", 
		"Resource=1", 
		"Referer=https://www.demoblaze.com/cart.html", 
		"Snapshot=t93.inf", 
		LAST);

	web_add_header("If-None-Match", 
		"\"TTo8pA\"");

	web_url("latostyle.css_4", 
		"URL=https://www.demoblaze.com/css/latostyle.css", 
		"Resource=1", 
		"Referer=https://www.demoblaze.com/cart.html", 
		"Snapshot=t94.inf", 
		LAST);

	web_add_header("If-None-Match", 
		"\"TTo8pA\"");

	web_url("jquery.min.js_4", 
		"URL=https://www.demoblaze.com/node_modules/jquery/dist/jquery.min.js", 
		"Resource=1", 
		"Referer=https://www.demoblaze.com/cart.html", 
		"Snapshot=t95.inf", 
		LAST);

	web_add_header("If-None-Match", 
		"\"TTo8pA\"");

	web_url("video.min.js_4", 
		"URL=https://www.demoblaze.com/node_modules/video.js/dist/video.min.js", 
		"Resource=1", 
		"Referer=https://www.demoblaze.com/cart.html", 
		"Snapshot=t96.inf", 
		LAST);

	web_add_header("If-None-Match", 
		"\"TTo8pA\"");

	web_url("videojs-contrib-hls.min.js_4", 
		"URL=https://www.demoblaze.com/node_modules/videojs-contrib-hls/dist/videojs-contrib-hls.min.js", 
		"Resource=1", 
		"Referer=https://www.demoblaze.com/cart.html", 
		"Snapshot=t98.inf", 
		LAST);

	web_add_header("If-None-Match", 
		"\"TTo8pA\"");

	web_url("tether.min.js_4", 
		"URL=https://www.demoblaze.com/node_modules/tether/dist/js/tether.min.js", 
		"Resource=1", 
		"Referer=https://www.demoblaze.com/cart.html", 
		"Snapshot=t99.inf", 
		LAST);

	web_add_header("If-None-Match", 
		"\"TTo8pA\"");

	web_url("bootstrap.min.js_4", 
		"URL=https://www.demoblaze.com/node_modules/bootstrap/dist/js/bootstrap.min.js", 
		"Resource=1", 
		"Referer=https://www.demoblaze.com/cart.html", 
		"Snapshot=t100.inf", 
		LAST);

	web_add_header("If-None-Match", 
		"\"TTo8pA\"");

	web_url("bm.png_4", 
		"URL=https://www.demoblaze.com/bm.png", 
		"Resource=1", 
		"Referer=https://www.demoblaze.com/cart.html", 
		"Snapshot=t101.inf", 
		LAST);

	web_url("cart.js", 
		"URL=https://www.demoblaze.com/js/cart.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=https://www.demoblaze.com/cart.html", 
		"Snapshot=t102.inf", 
		LAST);

	web_url("sweetalert.min.js", 
		"URL=https://www.demoblaze.com/node_modules/bootstrap-sweetalert/dist/sweetalert.min.js", 
		"Resource=1", 
		"RecContentType=application/javascript", 
		"Referer=https://www.demoblaze.com/cart.html", 
		"Snapshot=t103.inf", 
		LAST);

	web_add_header("If-None-Match", 
		"\"TTo8pA\"");

	web_url("favicon.ico_6", 
		"URL=https://www.demoblaze.com/favicon.ico", 
		"Resource=1", 
		"Referer=https://www.demoblaze.com/cart.html", 
		"Snapshot=t104.inf", 
		LAST);

	web_concurrent_end(NULL);

	web_add_header("If-None-Match", 
		"\"TTo8pA\"");

	web_url("front.jpg_4", 
		"URL=https://www.demoblaze.com/imgs/front.jpg", 
		"Resource=1", 
		"Referer=https://www.demoblaze.com/cart.html", 
		"Snapshot=t97.inf", 
		LAST);

	web_add_header("X-Requested-With", 
		"XMLHttpRequest");

	web_add_header("If-None-Match", 
		"\"TTo8pA\"");

	web_url("config.json_4", 
		"URL=https://www.demoblaze.com/config.json", 
		"Resource=1", 
		"Referer=https://www.demoblaze.com/cart.html", 
		"Snapshot=t105.inf", 
		LAST);

	web_revert_auto_header("sec-ch-ua");

	web_revert_auto_header("sec-ch-ua-mobile");

	web_revert_auto_header("sec-ch-ua-platform");

	web_add_auto_header("Access-Control-Request-Headers", 
		"content-type");

	web_add_auto_header("Access-Control-Request-Method", 
		"POST");

	web_add_auto_header("Origin", 
		"https://www.demoblaze.com");

	web_add_auto_header("Sec-Fetch-Dest", 
		"empty");

	web_add_auto_header("Sec-Fetch-Mode", 
		"cors");

	web_add_auto_header("Sec-Fetch-Site", 
		"same-site");

	web_custom_request("check_5", 
		"URL=https://api.demoblaze.com/check", 
		"Method=OPTIONS", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://www.demoblaze.com/", 
		"Snapshot=t106.inf", 
		"Mode=HTTP", 
		LAST);

	web_custom_request("viewcart", 
		"URL=https://api.demoblaze.com/viewcart", 
		"Method=OPTIONS", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://www.demoblaze.com/", 
		"Snapshot=t107.inf", 
		"Mode=HTTP", 
		LAST);

	web_revert_auto_header("Access-Control-Request-Headers");

	web_revert_auto_header("Access-Control-Request-Method");

	web_add_auto_header("sec-ch-ua", 
		"\"Google Chrome\";v=\"131\", \"Chromium\";v=\"131\", \"Not_A Brand\";v=\"24\"");

	web_add_auto_header("sec-ch-ua-mobile", 
		"?0");

	web_add_auto_header("sec-ch-ua-platform", 
		"\"Windows\"");

	web_custom_request("check_6", 
		"URL=https://api.demoblaze.com/check", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://www.demoblaze.com/", 
		"Snapshot=t108.inf", 
		"Mode=HTTP", 
		"EncType=application/json", 
		"Body={\"token\":\"dG9tamVycnkyMDI0MTczNDU5OA==\"}", 
		LAST);

	web_custom_request("viewcart_2", 
		"URL=https://api.demoblaze.com/viewcart", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://www.demoblaze.com/", 
		"Snapshot=t109.inf", 
		"Mode=HTTP", 
		"EncType=application/json", 
		"Body={\"cookie\":\"dG9tamVycnkyMDI0MTczNDU5OA==\",\"flag\":true}", 
		LAST);

	web_revert_auto_header("sec-ch-ua");

	web_revert_auto_header("sec-ch-ua-mobile");

	web_revert_auto_header("sec-ch-ua-platform");

	web_add_header("Access-Control-Request-Headers", 
		"content-type");

	web_add_header("Access-Control-Request-Method", 
		"POST");

	web_custom_request("view_3", 
		"URL=https://api.demoblaze.com/view", 
		"Method=OPTIONS", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://www.demoblaze.com/", 
		"Snapshot=t110.inf", 
		"Mode=HTTP", 
		LAST);

	web_add_auto_header("sec-ch-ua-platform", 
		"\"Windows\"");

	web_add_auto_header("sec-ch-ua", 
		"\"Google Chrome\";v=\"131\", \"Chromium\";v=\"131\", \"Not_A Brand\";v=\"24\"");

	web_add_auto_header("sec-ch-ua-mobile", 
		"?0");

	web_custom_request("view_4", 
		"URL=https://api.demoblaze.com/view", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://www.demoblaze.com/", 
		"Snapshot=t111.inf", 
		"Mode=HTTP", 
		"EncType=application/json", 
		"Body={\"id\":8}", 
		LAST);

	web_add_header("If-None-Match", 
		"\"TTo8pA\"");

	web_url("sony_vaio_5.jpg_4", 
		"URL=https://www.demoblaze.com/imgs/sony_vaio_5.jpg", 
		"Resource=1", 
		"Referer=https://www.demoblaze.com/cart.html", 
		"Snapshot=t112.inf", 
		LAST);

	lr_end_transaction("GoToCart",LR_AUTO);

	lr_start_transaction("PlaceOrder");

	web_revert_auto_header("sec-ch-ua");

	web_revert_auto_header("sec-ch-ua-mobile");

	web_revert_auto_header("sec-ch-ua-platform");

	web_add_header("Access-Control-Request-Headers", 
		"content-type");

	web_add_header("Access-Control-Request-Method", 
		"POST");

	web_custom_request("deletecart", 
		"URL=https://api.demoblaze.com/deletecart", 
		"Method=OPTIONS", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://www.demoblaze.com/", 
		"Snapshot=t113.inf", 
		"Mode=HTTP", 
		LAST);

	web_add_auto_header("sec-ch-ua", 
		"\"Google Chrome\";v=\"131\", \"Chromium\";v=\"131\", \"Not_A Brand\";v=\"24\"");

	web_add_auto_header("sec-ch-ua-mobile", 
		"?0");

	web_add_auto_header("sec-ch-ua-platform", 
		"\"Windows\"");

	web_custom_request("deletecart_2", 
		"URL=https://api.demoblaze.com/deletecart", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://www.demoblaze.com/", 
		"Snapshot=t114.inf", 
		"Mode=HTTP", 
		"EncType=application/json", 
		"Body={\"cookie\":\"tomjerry2024\"}", 
		LAST);

	web_revert_auto_header("Origin");

	web_add_auto_header("Sec-Fetch-Mode", 
		"navigate");

	web_add_auto_header("Sec-Fetch-Site", 
		"same-origin");

	web_add_auto_header("Sec-Fetch-Dest", 
		"document");

	web_add_header("Sec-Fetch-User", 
		"?1");

	web_add_header("Upgrade-Insecure-Requests", 
		"1");

	web_url("index.html", 
		"URL=https://www.demoblaze.com/index.html", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://www.demoblaze.com/cart.html", 
		"Snapshot=t115.inf", 
		"Mode=HTTP", 
		LAST);

	web_add_header("If-None-Match", 
		"\"TTo8pA\"");

	web_concurrent_start(NULL);

	web_url("video-js.min.css_5", 
		"URL=https://www.demoblaze.com/node_modules/video.js/dist/video-js.min.css", 
		"Resource=1", 
		"Referer=https://www.demoblaze.com/index.html", 
		"Snapshot=t116.inf", 
		LAST);

	web_add_header("If-None-Match", 
		"\"TTo8pA\"");

	web_url("latofonts.css_5", 
		"URL=https://www.demoblaze.com/css/latofonts.css", 
		"Resource=1", 
		"Referer=https://www.demoblaze.com/index.html", 
		"Snapshot=t117.inf", 
		LAST);

	web_add_header("If-None-Match", 
		"\"TTo8pA\"");

	web_url("jquery.min.js_5", 
		"URL=https://www.demoblaze.com/node_modules/jquery/dist/jquery.min.js", 
		"Resource=1", 
		"Referer=https://www.demoblaze.com/index.html", 
		"Snapshot=t118.inf", 
		LAST);

	web_add_header("If-None-Match", 
		"\"TTo8pA\"");

	web_url("bootstrap.min.css_5", 
		"URL=https://www.demoblaze.com/node_modules/bootstrap/dist/css/bootstrap.min.css", 
		"Resource=1", 
		"Referer=https://www.demoblaze.com/index.html", 
		"Snapshot=t119.inf", 
		LAST);

	web_add_header("If-None-Match", 
		"\"TTo8pA\"");

	web_url("latostyle.css_5", 
		"URL=https://www.demoblaze.com/css/latostyle.css", 
		"Resource=1", 
		"Referer=https://www.demoblaze.com/index.html", 
		"Snapshot=t120.inf", 
		LAST);

	web_add_header("If-None-Match", 
		"\"TTo8pA\"");

	web_url("video.min.js_5", 
		"URL=https://www.demoblaze.com/node_modules/video.js/dist/video.min.js", 
		"Resource=1", 
		"Referer=https://www.demoblaze.com/index.html", 
		"Snapshot=t122.inf", 
		LAST);

	web_add_header("If-None-Match", 
		"\"TTo8pA\"");

	web_url("Samsung1.jpg_3", 
		"URL=https://www.demoblaze.com/Samsung1.jpg", 
		"Resource=1", 
		"Referer=https://www.demoblaze.com/index.html", 
		"Snapshot=t123.inf", 
		LAST);

	web_add_header("If-None-Match", 
		"\"TTo8pA\"");

	web_url("iphone1.jpg_3", 
		"URL=https://www.demoblaze.com/iphone1.jpg", 
		"Resource=1", 
		"Referer=https://www.demoblaze.com/index.html", 
		"Snapshot=t124.inf", 
		LAST);

	web_add_header("If-None-Match", 
		"\"TTo8pA\"");

	web_url("nexus1.jpg_3", 
		"URL=https://www.demoblaze.com/nexus1.jpg", 
		"Resource=1", 
		"Referer=https://www.demoblaze.com/index.html", 
		"Snapshot=t125.inf", 
		LAST);

	web_add_header("If-None-Match", 
		"\"TTo8pA\"");

	web_url("bm.png_5", 
		"URL=https://www.demoblaze.com/bm.png", 
		"Resource=1", 
		"Referer=https://www.demoblaze.com/index.html", 
		"Snapshot=t126.inf", 
		LAST);

	web_add_header("If-None-Match", 
		"\"TTo8pA\"");

	web_url("tether.min.js_5", 
		"URL=https://www.demoblaze.com/node_modules/tether/dist/js/tether.min.js", 
		"Resource=1", 
		"Referer=https://www.demoblaze.com/index.html", 
		"Snapshot=t127.inf", 
		LAST);

	web_add_header("If-None-Match", 
		"\"TTo8pA\"");

	web_url("videojs-contrib-hls.min.js_5", 
		"URL=https://www.demoblaze.com/node_modules/videojs-contrib-hls/dist/videojs-contrib-hls.min.js", 
		"Resource=1", 
		"Referer=https://www.demoblaze.com/index.html", 
		"Snapshot=t128.inf", 
		LAST);

	web_add_header("If-None-Match", 
		"\"TTo8pA\"");

	web_url("bootstrap.min.js_5", 
		"URL=https://www.demoblaze.com/node_modules/bootstrap/dist/js/bootstrap.min.js", 
		"Resource=1", 
		"Referer=https://www.demoblaze.com/index.html", 
		"Snapshot=t129.inf", 
		LAST);

	web_add_header("If-None-Match", 
		"\"TTo8pA\"");

	web_url("index.js_3", 
		"URL=https://www.demoblaze.com/js/index.js", 
		"Resource=1", 
		"Referer=https://www.demoblaze.com/index.html", 
		"Snapshot=t130.inf", 
		LAST);

	web_add_header("If-None-Match", 
		"\"TTo8pA\"");

	web_url("favicon.ico_7", 
		"URL=https://www.demoblaze.com/favicon.ico", 
		"Resource=1", 
		"Referer=https://www.demoblaze.com/index.html", 
		"Snapshot=t131.inf", 
		LAST);

	web_concurrent_end(NULL);

	web_add_header("If-None-Match", 
		"\"TTo8pA\"");

	web_url("front.jpg_5", 
		"URL=https://www.demoblaze.com/imgs/front.jpg", 
		"Resource=1", 
		"Referer=https://www.demoblaze.com/index.html", 
		"Snapshot=t121.inf", 
		LAST);

	web_add_header("X-Requested-With", 
		"XMLHttpRequest");

	web_add_header("If-None-Match", 
		"\"TTo8pA\"");

	web_url("config.json_5", 
		"URL=https://www.demoblaze.com/config.json", 
		"Resource=1", 
		"Referer=https://www.demoblaze.com/index.html", 
		"Snapshot=t132.inf", 
		LAST);

	web_revert_auto_header("sec-ch-ua");

	web_revert_auto_header("sec-ch-ua-mobile");

	web_revert_auto_header("sec-ch-ua-platform");

	web_add_header("Access-Control-Request-Headers", 
		"content-type");

	web_add_header("Access-Control-Request-Method", 
		"POST");

	web_add_auto_header("Origin", 
		"https://www.demoblaze.com");

	web_add_auto_header("Sec-Fetch-Dest", 
		"empty");

	web_add_auto_header("Sec-Fetch-Mode", 
		"cors");

	web_add_auto_header("Sec-Fetch-Site", 
		"same-site");

	web_custom_request("check_7", 
		"URL=https://api.demoblaze.com/check", 
		"Method=OPTIONS", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://www.demoblaze.com/", 
		"Snapshot=t133.inf", 
		"Mode=HTTP", 
		LAST);

	web_add_auto_header("sec-ch-ua", 
		"\"Google Chrome\";v=\"131\", \"Chromium\";v=\"131\", \"Not_A Brand\";v=\"24\"");

	web_add_auto_header("sec-ch-ua-mobile", 
		"?0");

	web_add_auto_header("sec-ch-ua-platform", 
		"\"Windows\"");

	web_url("entries_3", 
		"URL=https://api.demoblaze.com/entries", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://www.demoblaze.com/", 
		"Snapshot=t134.inf", 
		"Mode=HTTP", 
		LAST);

	web_custom_request("check_8", 
		"URL=https://api.demoblaze.com/check", 
		"Method=POST", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://www.demoblaze.com/", 
		"Snapshot=t135.inf", 
		"Mode=HTTP", 
		"EncType=application/json", 
		"Body={\"token\":\"dG9tamVycnkyMDI0MTczNDU5OA==\"}", 
		LAST);

	web_add_header("If-None-Match", 
		"\"TTo8pA\"");

	web_concurrent_start(NULL);

	web_url("Nexus_6.jpg_3", 
		"URL=https://www.demoblaze.com/imgs/Nexus_6.jpg", 
		"Resource=1", 
		"Referer=https://www.demoblaze.com/index.html", 
		"Snapshot=t136.inf", 
		LAST);

	web_add_header("If-None-Match", 
		"\"TTo8pA\"");

	web_url("sony_vaio_5.jpg_5", 
		"URL=https://www.demoblaze.com/imgs/sony_vaio_5.jpg", 
		"Resource=1", 
		"Referer=https://www.demoblaze.com/index.html", 
		"Snapshot=t137.inf", 
		LAST);

	web_add_header("If-None-Match", 
		"\"TTo8pA\"");

	web_url("galaxy_s6.jpg_3", 
		"URL=https://www.demoblaze.com/imgs/galaxy_s6.jpg", 
		"Resource=1", 
		"Referer=https://www.demoblaze.com/index.html", 
		"Snapshot=t138.inf", 
		LAST);

	web_add_header("If-None-Match", 
		"\"TTo8pA\"");

	web_url("iphone_6.jpg_3", 
		"URL=https://www.demoblaze.com/imgs/iphone_6.jpg", 
		"Resource=1", 
		"Referer=https://www.demoblaze.com/index.html", 
		"Snapshot=t139.inf", 
		LAST);

	web_add_header("If-None-Match", 
		"\"TTo8pA\"");

	web_url("xperia_z5.jpg_3", 
		"URL=https://www.demoblaze.com/imgs/xperia_z5.jpg", 
		"Resource=1", 
		"Referer=https://www.demoblaze.com/index.html", 
		"Snapshot=t140.inf", 
		LAST);

	web_add_header("If-None-Match", 
		"\"TTo8pA\"");

	web_url("HTC_M9.jpg_3", 
		"URL=https://www.demoblaze.com/imgs/HTC_M9.jpg", 
		"Resource=1", 
		"Referer=https://www.demoblaze.com/index.html", 
		"Snapshot=t141.inf", 
		LAST);

	web_add_header("If-None-Match", 
		"\"TTo8pA\"");

	web_url("Lumia_1520.jpg_3", 
		"URL=https://www.demoblaze.com/imgs/Lumia_1520.jpg", 
		"Resource=1", 
		"Referer=https://www.demoblaze.com/index.html", 
		"Snapshot=t142.inf", 
		LAST);

	web_concurrent_end(NULL);

	lr_end_transaction("PlaceOrder",LR_AUTO);

	lr_start_transaction("LogOut");

	web_revert_auto_header("Origin");

	web_add_auto_header("Sec-Fetch-Mode", 
		"navigate");

	web_add_auto_header("Sec-Fetch-Dest", 
		"document");

	web_add_auto_header("If-None-Match", 
		"\"TTo8pA\"");

	web_add_auto_header("Sec-Fetch-Site", 
		"same-origin");

	web_add_header("Sec-Fetch-User", 
		"?1");

	web_add_header("Upgrade-Insecure-Requests", 
		"1");

	lr_think_time(13);

	web_url("index.html_2", 
		"URL=https://www.demoblaze.com/index.html", 
		"Resource=0", 
		"Referer=https://www.demoblaze.com/index.html", 
		"Snapshot=t143.inf", 
		"Mode=HTTP", 
		LAST);

	web_add_auto_header("Sec-Fetch-Dest", 
		"style");

	web_add_auto_header("Sec-Fetch-Mode", 
		"no-cors");

	web_url("video-js.min.css_6", 
		"URL=https://www.demoblaze.com/node_modules/video.js/dist/video-js.min.css", 
		"Resource=1", 
		"Referer=https://www.demoblaze.com/index.html", 
		"Snapshot=t144.inf", 
		LAST);

	web_add_auto_header("Sec-Fetch-Dest", 
		"script");

	web_url("jquery.min.js_6", 
		"URL=https://www.demoblaze.com/node_modules/jquery/dist/jquery.min.js", 
		"Resource=1", 
		"Referer=https://www.demoblaze.com/index.html", 
		"Snapshot=t145.inf", 
		LAST);

	web_add_auto_header("Sec-Fetch-Dest", 
		"style");

	web_url("latofonts.css_6", 
		"URL=https://www.demoblaze.com/css/latofonts.css", 
		"Resource=1", 
		"Referer=https://www.demoblaze.com/index.html", 
		"Snapshot=t146.inf", 
		LAST);

	web_url("bootstrap.min.css_6", 
		"URL=https://www.demoblaze.com/node_modules/bootstrap/dist/css/bootstrap.min.css", 
		"Resource=1", 
		"Referer=https://www.demoblaze.com/index.html", 
		"Snapshot=t147.inf", 
		LAST);

	web_add_auto_header("Sec-Fetch-Dest", 
		"image");

	web_url("Samsung1.jpg_4", 
		"URL=https://www.demoblaze.com/Samsung1.jpg", 
		"Resource=1", 
		"Referer=https://www.demoblaze.com/index.html", 
		"Snapshot=t148.inf", 
		LAST);

	web_add_auto_header("Sec-Fetch-Dest", 
		"style");

	web_url("latostyle.css_6", 
		"URL=https://www.demoblaze.com/css/latostyle.css", 
		"Resource=1", 
		"Referer=https://www.demoblaze.com/index.html", 
		"Snapshot=t149.inf", 
		LAST);

	web_url("front.jpg_6", 
		"URL=https://www.demoblaze.com/imgs/front.jpg", 
		"Resource=1", 
		"Referer=https://www.demoblaze.com/index.html", 
		"Snapshot=t150.inf", 
		LAST);

	web_add_auto_header("Sec-Fetch-Dest", 
		"image");

	web_url("nexus1.jpg_4", 
		"URL=https://www.demoblaze.com/nexus1.jpg", 
		"Resource=1", 
		"Referer=https://www.demoblaze.com/index.html", 
		"Snapshot=t151.inf", 
		LAST);

	web_add_auto_header("Sec-Fetch-Dest", 
		"script");

	web_url("video.min.js_6", 
		"URL=https://www.demoblaze.com/node_modules/video.js/dist/video.min.js", 
		"Resource=1", 
		"Referer=https://www.demoblaze.com/index.html", 
		"Snapshot=t152.inf", 
		LAST);

	web_add_auto_header("Sec-Fetch-Dest", 
		"image");

	web_url("iphone1.jpg_4", 
		"URL=https://www.demoblaze.com/iphone1.jpg", 
		"Resource=1", 
		"Referer=https://www.demoblaze.com/index.html", 
		"Snapshot=t153.inf", 
		LAST);

	web_add_auto_header("Sec-Fetch-Dest", 
		"script");

	web_url("tether.min.js_6", 
		"URL=https://www.demoblaze.com/node_modules/tether/dist/js/tether.min.js", 
		"Resource=1", 
		"Referer=https://www.demoblaze.com/index.html", 
		"Snapshot=t154.inf", 
		LAST);

	web_url("videojs-contrib-hls.min.js_6", 
		"URL=https://www.demoblaze.com/node_modules/videojs-contrib-hls/dist/videojs-contrib-hls.min.js", 
		"Resource=1", 
		"Referer=https://www.demoblaze.com/index.html", 
		"Snapshot=t155.inf", 
		LAST);

	web_url("bootstrap.min.js_6", 
		"URL=https://www.demoblaze.com/node_modules/bootstrap/dist/js/bootstrap.min.js", 
		"Resource=1", 
		"Referer=https://www.demoblaze.com/index.html", 
		"Snapshot=t156.inf", 
		LAST);

	web_add_auto_header("Sec-Fetch-Dest", 
		"image");

	web_url("bm.png_6", 
		"URL=https://www.demoblaze.com/bm.png", 
		"Resource=1", 
		"Referer=https://www.demoblaze.com/index.html", 
		"Snapshot=t157.inf", 
		LAST);

	web_add_auto_header("Sec-Fetch-Dest", 
		"script");

	web_url("index.js_4", 
		"URL=https://www.demoblaze.com/js/index.js", 
		"Resource=1", 
		"Referer=https://www.demoblaze.com/index.html", 
		"Snapshot=t158.inf", 
		LAST);

	web_add_auto_header("Sec-Fetch-Dest", 
		"image");

	web_url("favicon.ico_8", 
		"URL=https://www.demoblaze.com/favicon.ico", 
		"Resource=1", 
		"Referer=https://www.demoblaze.com/index.html", 
		"Snapshot=t159.inf", 
		LAST);

	web_add_header("X-Requested-With", 
		"XMLHttpRequest");

	web_url("config.json_6", 
		"URL=https://www.demoblaze.com/config.json", 
		"Resource=1", 
		"Referer=https://www.demoblaze.com/index.html", 
		"Snapshot=t160.inf", 
		LAST);

	web_revert_auto_header("If-None-Match");

	web_add_header("Origin", 
		"https://www.demoblaze.com");

	web_add_auto_header("Sec-Fetch-Dest", 
		"empty");

	web_add_auto_header("Sec-Fetch-Mode", 
		"cors");

	web_add_auto_header("Sec-Fetch-Site", 
		"same-site");

	web_url("entries_4", 
		"URL=https://api.demoblaze.com/entries", 
		"Resource=0", 
		"RecContentType=application/json", 
		"Referer=https://www.demoblaze.com/", 
		"Snapshot=t161.inf", 
		"Mode=HTTP", 
		LAST);

	web_add_header("If-None-Match", 
		"\"TTo8pA\"");

	web_concurrent_start(NULL);

	web_url("Lumia_1520.jpg_4", 
		"URL=https://www.demoblaze.com/imgs/Lumia_1520.jpg", 
		"Resource=1", 
		"Referer=https://www.demoblaze.com/index.html", 
		"Snapshot=t162.inf", 
		LAST);

	web_add_header("If-None-Match", 
		"\"TTo8pA\"");

	web_url("Nexus_6.jpg_4", 
		"URL=https://www.demoblaze.com/imgs/Nexus_6.jpg", 
		"Resource=1", 
		"Referer=https://www.demoblaze.com/index.html", 
		"Snapshot=t163.inf", 
		LAST);

	web_add_header("If-None-Match", 
		"\"TTo8pA\"");

	web_url("galaxy_s6.jpg_4", 
		"URL=https://www.demoblaze.com/imgs/galaxy_s6.jpg", 
		"Resource=1", 
		"Referer=https://www.demoblaze.com/index.html", 
		"Snapshot=t164.inf", 
		LAST);

	web_add_header("If-None-Match", 
		"\"TTo8pA\"");

	web_url("iphone_6.jpg_4", 
		"URL=https://www.demoblaze.com/imgs/iphone_6.jpg", 
		"Resource=1", 
		"Referer=https://www.demoblaze.com/index.html", 
		"Snapshot=t165.inf", 
		LAST);

	web_add_header("If-None-Match", 
		"\"TTo8pA\"");

	web_url("sony_vaio_5.jpg_6", 
		"URL=https://www.demoblaze.com/imgs/sony_vaio_5.jpg", 
		"Resource=1", 
		"Referer=https://www.demoblaze.com/index.html", 
		"Snapshot=t166.inf", 
		LAST);

	web_add_header("If-None-Match", 
		"\"TTo8pA\"");

	web_url("HTC_M9.jpg_4", 
		"URL=https://www.demoblaze.com/imgs/HTC_M9.jpg", 
		"Resource=1", 
		"Referer=https://www.demoblaze.com/index.html", 
		"Snapshot=t167.inf", 
		LAST);

	web_add_header("If-None-Match", 
		"\"TTo8pA\"");

	web_url("xperia_z5.jpg_4", 
		"URL=https://www.demoblaze.com/imgs/xperia_z5.jpg", 
		"Resource=1", 
		"Referer=https://www.demoblaze.com/index.html", 
		"Snapshot=t168.inf", 
		LAST);

	web_concurrent_end(NULL);

	lr_end_transaction("LogOut",LR_AUTO);

	return 0;
}