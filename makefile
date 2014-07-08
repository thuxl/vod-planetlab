all: pgetip p_server p_peer000 p_peer001 p_peer002 p_peer003 p_peer004 p_peer005 p_peer006 p_peer007 p_peer008 p_peer009 p_peer010 p_peer011 p_peer012 p_peer013 p_peer014 p_peer015 p_peer016 p_peer017 p_peer018 p_peer019 p_peer020 p_peer021 p_peer022 p_peer023 p_peer024 p_peer025 p_peer026 p_peer027 p_peer028 p_peer029 p_peer030 p_peer031 p_peer032 p_peer033 p_peer034 p_peer035 p_peer036 p_peer037 p_peer038 p_peer039 p_peer040 p_peer041 p_peer042 p_peer043 p_peer044 p_peer045 p_peer046 p_peer047 p_peer048 p_peer049 p_peer050 p_peer051 p_peer052 p_peer053 p_peer054 p_peer055 p_peer056 p_peer057 p_peer058 p_peer059 p_peer060 p_peer061 p_peer062 p_peer063 p_peer064 p_peer065 p_peer066 p_peer067 p_peer068 p_peer069 p_peer070 p_peer071 p_peer072 p_peer073 p_peer074 p_peer075 p_peer076 p_peer077 p_peer078 p_peer079 p_peer080 p_peer081 p_peer082 p_peer083 p_peer084 p_peer085 p_peer086 p_peer087 p_peer088 p_peer089 p_peer090 p_peer091 p_peer092 p_peer093 p_peer094 p_peer095 p_peer096 p_peer097 p_peer098 p_peer099 p_peer100 p_peer101 p_peer102 p_peer103 p_peer104 p_peer105 p_peer106 p_peer107 p_peer108 p_peer109 p_peer110 p_peer111 p_peer112 p_peer113 p_peer114 p_peer115 p_peer116 p_peer117 p_peer118 p_peer119 p_peer120 p_peer121 p_peer122 p_peer123 p_peer124 p_peer125 p_peer126 p_peer127 p_peer128 p_peer129 p_peer130 p_peer131 p_peer132 p_peer133 p_peer134 p_peer135 p_peer136 p_peer137 p_peer138 p_peer139 p_peer140 p_peer141 p_peer142 p_peer143 p_peer144 p_peer145 p_peer146 p_peer147 p_peer148 p_peer149 p_peer150 p_peer151 p_peer152 p_peer153 p_peer154 p_peer155 p_peer156 p_peer157 p_peer158 p_peer159 p_peer160 p_peer161 p_peer162 p_peer163 p_peer164 p_peer165 p_peer166 p_peer167 p_peer168 p_peer169 p_peer170 p_peer171 p_peer172 p_peer173 p_peer174 p_peer175 p_peer176 p_peer177 p_peer178 p_peer179 p_peer180 p_peer181 p_peer182 p_peer183 p_peer184 p_peer185 p_peer186 p_peer187 p_peer188 p_peer189 p_peer190 p_peer191 p_peer192 p_peer193 p_peer194 p_peer195 p_peer196 p_peer197 p_peer198 p_peer199 p_peer200 p_peer201 p_peer202 p_peer203 p_peer204 p_peer205 p_peer206 p_peer207 p_peer208 p_peer209 p_peer210 p_peer211 p_peer212 p_peer213 p_peer214 p_peer215 p_peer216 p_peer217 p_peer218 p_peer219 p_peer220 p_peer221 p_peer222 p_peer223 p_peer224 p_peer225 p_peer226 p_peer227 p_peer228 p_peer229 p_peer230 p_peer231 p_peer232 p_peer233 p_peer234 p_peer235 p_peer236 p_peer237 p_peer238 p_peer239 p_peer240 p_peer241 p_peer242 p_peer243 p_peer244 p_peer245 p_peer246 p_peer247 p_peer248 p_peer249 p_peer250 p_peer251 p_peer252 p_peer253 p_peer254 p_peer255 p_peer256 p_peer257 p_peer258 p_peer259 p_peer260 p_peer261 p_peer262 p_peer263 p_peer264 p_peer265 p_peer266 p_peer267 p_peer268 p_peer269 p_peer270 p_peer271 p_peer272 p_peer273 p_peer274 p_peer275 p_peer276 p_peer277 p_peer278 p_peer279 p_peer280 p_peer281 p_peer282 p_peer283 p_peer284 p_peer285 p_peer286 p_peer287 p_peer288 p_peer289 p_peer290 p_peer291 p_peer292 p_peer293 p_peer294 p_peer295 p_peer296 p_peer297 p_peer298 p_peer299 p_peer300 p_peer301 p_peer302 p_peer303 p_peer304 p_peer305 p_peer306 p_peer307 p_peer308 p_peer309 p_peer310 p_peer311 p_peer312 p_peer313 p_peer314 p_peer315 p_peer316 p_peer317 p_peer318 p_peer319 p_peer320 p_peer321 p_peer322 p_peer323 p_peer324 p_peer325 p_peer326 p_peer327 p_peer328 p_peer329 p_peer330 p_peer331 p_peer332 p_peer333 p_peer334 p_peer335 p_peer336 p_peer337 p_peer338 p_peer339 p_peer340 p_peer341 p_peer342 p_peer343 p_peer344 p_peer345 p_peer346 p_peer347 p_peer348 p_peer349 p_peer350 p_peer351 p_peer352 p_peer353 p_peer354 p_peer355 p_peer356 p_peer357 p_peer358 p_peer359 p_peer360 p_peer361 p_peer362 p_peer363 p_peer364 p_peer365 p_peer366 p_peer367 p_peer368 p_peer369 p_peer370 p_peer371 p_peer372 p_peer373 p_peer374 p_peer375 p_peer376 p_peer377 p_peer378 p_peer379 p_peer380 p_peer381 p_peer382 p_peer383 p_peer384 p_peer385 p_peer386 p_peer387 p_peer388 p_peer389 p_peer390 p_peer391 p_peer392 p_peer393 p_peer394 p_peer395 p_peer396 p_peer397 p_peer398 p_peer399 
pgetip: get_all_ip2.cc
	g++ -g -o pgetip get_all_ip2.cc
p_server:  node.cc server.cc servermain.cc
	g++  -g -rdynamic -o p_server  node.cc server.cc servermain.cc -lpthread
p_peer000: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=0 -o p_peers/p_peer000 node.cc peer.cc   peermain_000.cc -lpthread
p_peer001: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=1 -o p_peers/p_peer001 node.cc peer.cc   peermain_000.cc -lpthread
p_peer002: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=2 -o p_peers/p_peer002 node.cc peer.cc   peermain_000.cc -lpthread
p_peer003: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=3 -o p_peers/p_peer003 node.cc peer.cc   peermain_000.cc -lpthread
p_peer004: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=4 -o p_peers/p_peer004 node.cc peer.cc   peermain_000.cc -lpthread
p_peer005: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=5 -o p_peers/p_peer005 node.cc peer.cc   peermain_000.cc -lpthread
p_peer006: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=6 -o p_peers/p_peer006 node.cc peer.cc   peermain_000.cc -lpthread
p_peer007: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=7 -o p_peers/p_peer007 node.cc peer.cc   peermain_000.cc -lpthread
p_peer008: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=8 -o p_peers/p_peer008 node.cc peer.cc   peermain_000.cc -lpthread
p_peer009: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=9 -o p_peers/p_peer009 node.cc peer.cc   peermain_000.cc -lpthread
p_peer010: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=10 -o p_peers/p_peer010 node.cc peer.cc   peermain_000.cc -lpthread
p_peer011: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=11 -o p_peers/p_peer011 node.cc peer.cc   peermain_000.cc -lpthread
p_peer012: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=12 -o p_peers/p_peer012 node.cc peer.cc   peermain_000.cc -lpthread
p_peer013: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=13 -o p_peers/p_peer013 node.cc peer.cc   peermain_000.cc -lpthread
p_peer014: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=14 -o p_peers/p_peer014 node.cc peer.cc   peermain_000.cc -lpthread
p_peer015: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=15 -o p_peers/p_peer015 node.cc peer.cc   peermain_000.cc -lpthread
p_peer016: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=16 -o p_peers/p_peer016 node.cc peer.cc   peermain_000.cc -lpthread
p_peer017: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=17 -o p_peers/p_peer017 node.cc peer.cc   peermain_000.cc -lpthread
p_peer018: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=18 -o p_peers/p_peer018 node.cc peer.cc   peermain_000.cc -lpthread
p_peer019: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=19 -o p_peers/p_peer019 node.cc peer.cc   peermain_000.cc -lpthread
p_peer020: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=20 -o p_peers/p_peer020 node.cc peer.cc   peermain_000.cc -lpthread
p_peer021: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=21 -o p_peers/p_peer021 node.cc peer.cc   peermain_000.cc -lpthread
p_peer022: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=22 -o p_peers/p_peer022 node.cc peer.cc   peermain_000.cc -lpthread
p_peer023: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=23 -o p_peers/p_peer023 node.cc peer.cc   peermain_000.cc -lpthread
p_peer024: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=24 -o p_peers/p_peer024 node.cc peer.cc   peermain_000.cc -lpthread
p_peer025: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=25 -o p_peers/p_peer025 node.cc peer.cc   peermain_000.cc -lpthread
p_peer026: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=26 -o p_peers/p_peer026 node.cc peer.cc   peermain_000.cc -lpthread
p_peer027: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=27 -o p_peers/p_peer027 node.cc peer.cc   peermain_000.cc -lpthread
p_peer028: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=28 -o p_peers/p_peer028 node.cc peer.cc   peermain_000.cc -lpthread
p_peer029: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=29 -o p_peers/p_peer029 node.cc peer.cc   peermain_000.cc -lpthread
p_peer030: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=30 -o p_peers/p_peer030 node.cc peer.cc   peermain_000.cc -lpthread
p_peer031: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=31 -o p_peers/p_peer031 node.cc peer.cc   peermain_000.cc -lpthread
p_peer032: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=32 -o p_peers/p_peer032 node.cc peer.cc   peermain_000.cc -lpthread
p_peer033: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=33 -o p_peers/p_peer033 node.cc peer.cc   peermain_000.cc -lpthread
p_peer034: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=34 -o p_peers/p_peer034 node.cc peer.cc   peermain_000.cc -lpthread
p_peer035: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=35 -o p_peers/p_peer035 node.cc peer.cc   peermain_000.cc -lpthread
p_peer036: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=36 -o p_peers/p_peer036 node.cc peer.cc   peermain_000.cc -lpthread
p_peer037: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=37 -o p_peers/p_peer037 node.cc peer.cc   peermain_000.cc -lpthread
p_peer038: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=38 -o p_peers/p_peer038 node.cc peer.cc   peermain_000.cc -lpthread
p_peer039: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=39 -o p_peers/p_peer039 node.cc peer.cc   peermain_000.cc -lpthread
p_peer040: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=40 -o p_peers/p_peer040 node.cc peer.cc   peermain_000.cc -lpthread
p_peer041: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=41 -o p_peers/p_peer041 node.cc peer.cc   peermain_000.cc -lpthread
p_peer042: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=42 -o p_peers/p_peer042 node.cc peer.cc   peermain_000.cc -lpthread
p_peer043: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=43 -o p_peers/p_peer043 node.cc peer.cc   peermain_000.cc -lpthread
p_peer044: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=44 -o p_peers/p_peer044 node.cc peer.cc   peermain_000.cc -lpthread
p_peer045: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=45 -o p_peers/p_peer045 node.cc peer.cc   peermain_000.cc -lpthread
p_peer046: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=46 -o p_peers/p_peer046 node.cc peer.cc   peermain_000.cc -lpthread
p_peer047: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=47 -o p_peers/p_peer047 node.cc peer.cc   peermain_000.cc -lpthread
p_peer048: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=48 -o p_peers/p_peer048 node.cc peer.cc   peermain_000.cc -lpthread
p_peer049: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=49 -o p_peers/p_peer049 node.cc peer.cc   peermain_000.cc -lpthread
p_peer050: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=50 -o p_peers/p_peer050 node.cc peer.cc   peermain_000.cc -lpthread
p_peer051: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=51 -o p_peers/p_peer051 node.cc peer.cc   peermain_000.cc -lpthread
p_peer052: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=52 -o p_peers/p_peer052 node.cc peer.cc   peermain_000.cc -lpthread
p_peer053: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=53 -o p_peers/p_peer053 node.cc peer.cc   peermain_000.cc -lpthread
p_peer054: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=54 -o p_peers/p_peer054 node.cc peer.cc   peermain_000.cc -lpthread
p_peer055: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=55 -o p_peers/p_peer055 node.cc peer.cc   peermain_000.cc -lpthread
p_peer056: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=56 -o p_peers/p_peer056 node.cc peer.cc   peermain_000.cc -lpthread
p_peer057: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=57 -o p_peers/p_peer057 node.cc peer.cc   peermain_000.cc -lpthread
p_peer058: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=58 -o p_peers/p_peer058 node.cc peer.cc   peermain_000.cc -lpthread
p_peer059: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=59 -o p_peers/p_peer059 node.cc peer.cc   peermain_000.cc -lpthread
p_peer060: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=60 -o p_peers/p_peer060 node.cc peer.cc   peermain_000.cc -lpthread
p_peer061: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=61 -o p_peers/p_peer061 node.cc peer.cc   peermain_000.cc -lpthread
p_peer062: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=62 -o p_peers/p_peer062 node.cc peer.cc   peermain_000.cc -lpthread
p_peer063: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=63 -o p_peers/p_peer063 node.cc peer.cc   peermain_000.cc -lpthread
p_peer064: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=64 -o p_peers/p_peer064 node.cc peer.cc   peermain_000.cc -lpthread
p_peer065: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=65 -o p_peers/p_peer065 node.cc peer.cc   peermain_000.cc -lpthread
p_peer066: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=66 -o p_peers/p_peer066 node.cc peer.cc   peermain_000.cc -lpthread
p_peer067: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=67 -o p_peers/p_peer067 node.cc peer.cc   peermain_000.cc -lpthread
p_peer068: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=68 -o p_peers/p_peer068 node.cc peer.cc   peermain_000.cc -lpthread
p_peer069: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=69 -o p_peers/p_peer069 node.cc peer.cc   peermain_000.cc -lpthread
p_peer070: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=70 -o p_peers/p_peer070 node.cc peer.cc   peermain_000.cc -lpthread
p_peer071: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=71 -o p_peers/p_peer071 node.cc peer.cc   peermain_000.cc -lpthread
p_peer072: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=72 -o p_peers/p_peer072 node.cc peer.cc   peermain_000.cc -lpthread
p_peer073: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=73 -o p_peers/p_peer073 node.cc peer.cc   peermain_000.cc -lpthread
p_peer074: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=74 -o p_peers/p_peer074 node.cc peer.cc   peermain_000.cc -lpthread
p_peer075: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=75 -o p_peers/p_peer075 node.cc peer.cc   peermain_000.cc -lpthread
p_peer076: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=76 -o p_peers/p_peer076 node.cc peer.cc   peermain_000.cc -lpthread
p_peer077: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=77 -o p_peers/p_peer077 node.cc peer.cc   peermain_000.cc -lpthread
p_peer078: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=78 -o p_peers/p_peer078 node.cc peer.cc   peermain_000.cc -lpthread
p_peer079: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=79 -o p_peers/p_peer079 node.cc peer.cc   peermain_000.cc -lpthread
p_peer080: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=80 -o p_peers/p_peer080 node.cc peer.cc   peermain_000.cc -lpthread
p_peer081: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=81 -o p_peers/p_peer081 node.cc peer.cc   peermain_000.cc -lpthread
p_peer082: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=82 -o p_peers/p_peer082 node.cc peer.cc   peermain_000.cc -lpthread
p_peer083: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=83 -o p_peers/p_peer083 node.cc peer.cc   peermain_000.cc -lpthread
p_peer084: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=84 -o p_peers/p_peer084 node.cc peer.cc   peermain_000.cc -lpthread
p_peer085: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=85 -o p_peers/p_peer085 node.cc peer.cc   peermain_000.cc -lpthread
p_peer086: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=86 -o p_peers/p_peer086 node.cc peer.cc   peermain_000.cc -lpthread
p_peer087: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=87 -o p_peers/p_peer087 node.cc peer.cc   peermain_000.cc -lpthread
p_peer088: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=88 -o p_peers/p_peer088 node.cc peer.cc   peermain_000.cc -lpthread
p_peer089: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=89 -o p_peers/p_peer089 node.cc peer.cc   peermain_000.cc -lpthread
p_peer090: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=90 -o p_peers/p_peer090 node.cc peer.cc   peermain_000.cc -lpthread
p_peer091: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=91 -o p_peers/p_peer091 node.cc peer.cc   peermain_000.cc -lpthread
p_peer092: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=92 -o p_peers/p_peer092 node.cc peer.cc   peermain_000.cc -lpthread
p_peer093: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=93 -o p_peers/p_peer093 node.cc peer.cc   peermain_000.cc -lpthread
p_peer094: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=94 -o p_peers/p_peer094 node.cc peer.cc   peermain_000.cc -lpthread
p_peer095: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=95 -o p_peers/p_peer095 node.cc peer.cc   peermain_000.cc -lpthread
p_peer096: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=96 -o p_peers/p_peer096 node.cc peer.cc   peermain_000.cc -lpthread
p_peer097: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=97 -o p_peers/p_peer097 node.cc peer.cc   peermain_000.cc -lpthread
p_peer098: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=98 -o p_peers/p_peer098 node.cc peer.cc   peermain_000.cc -lpthread
p_peer099: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=99 -o p_peers/p_peer099 node.cc peer.cc   peermain_000.cc -lpthread
p_peer100: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=100 -o p_peers/p_peer100 node.cc peer.cc   peermain_000.cc -lpthread
p_peer101: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=101 -o p_peers/p_peer101 node.cc peer.cc   peermain_000.cc -lpthread
p_peer102: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=102 -o p_peers/p_peer102 node.cc peer.cc   peermain_000.cc -lpthread
p_peer103: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=103 -o p_peers/p_peer103 node.cc peer.cc   peermain_000.cc -lpthread
p_peer104: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=104 -o p_peers/p_peer104 node.cc peer.cc   peermain_000.cc -lpthread
p_peer105: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=105 -o p_peers/p_peer105 node.cc peer.cc   peermain_000.cc -lpthread
p_peer106: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=106 -o p_peers/p_peer106 node.cc peer.cc   peermain_000.cc -lpthread
p_peer107: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=107 -o p_peers/p_peer107 node.cc peer.cc   peermain_000.cc -lpthread
p_peer108: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=108 -o p_peers/p_peer108 node.cc peer.cc   peermain_000.cc -lpthread
p_peer109: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=109 -o p_peers/p_peer109 node.cc peer.cc   peermain_000.cc -lpthread
p_peer110: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=110 -o p_peers/p_peer110 node.cc peer.cc   peermain_000.cc -lpthread
p_peer111: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=111 -o p_peers/p_peer111 node.cc peer.cc   peermain_000.cc -lpthread
p_peer112: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=112 -o p_peers/p_peer112 node.cc peer.cc   peermain_000.cc -lpthread
p_peer113: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=113 -o p_peers/p_peer113 node.cc peer.cc   peermain_000.cc -lpthread
p_peer114: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=114 -o p_peers/p_peer114 node.cc peer.cc   peermain_000.cc -lpthread
p_peer115: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=115 -o p_peers/p_peer115 node.cc peer.cc   peermain_000.cc -lpthread
p_peer116: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=116 -o p_peers/p_peer116 node.cc peer.cc   peermain_000.cc -lpthread
p_peer117: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=117 -o p_peers/p_peer117 node.cc peer.cc   peermain_000.cc -lpthread
p_peer118: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=118 -o p_peers/p_peer118 node.cc peer.cc   peermain_000.cc -lpthread
p_peer119: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=119 -o p_peers/p_peer119 node.cc peer.cc   peermain_000.cc -lpthread
p_peer120: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=120 -o p_peers/p_peer120 node.cc peer.cc   peermain_000.cc -lpthread
p_peer121: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=121 -o p_peers/p_peer121 node.cc peer.cc   peermain_000.cc -lpthread
p_peer122: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=122 -o p_peers/p_peer122 node.cc peer.cc   peermain_000.cc -lpthread
p_peer123: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=123 -o p_peers/p_peer123 node.cc peer.cc   peermain_000.cc -lpthread
p_peer124: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=124 -o p_peers/p_peer124 node.cc peer.cc   peermain_000.cc -lpthread
p_peer125: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=125 -o p_peers/p_peer125 node.cc peer.cc   peermain_000.cc -lpthread
p_peer126: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=126 -o p_peers/p_peer126 node.cc peer.cc   peermain_000.cc -lpthread
p_peer127: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=127 -o p_peers/p_peer127 node.cc peer.cc   peermain_000.cc -lpthread
p_peer128: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=128 -o p_peers/p_peer128 node.cc peer.cc   peermain_000.cc -lpthread
p_peer129: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=129 -o p_peers/p_peer129 node.cc peer.cc   peermain_000.cc -lpthread
p_peer130: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=130 -o p_peers/p_peer130 node.cc peer.cc   peermain_000.cc -lpthread
p_peer131: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=131 -o p_peers/p_peer131 node.cc peer.cc   peermain_000.cc -lpthread
p_peer132: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=132 -o p_peers/p_peer132 node.cc peer.cc   peermain_000.cc -lpthread
p_peer133: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=133 -o p_peers/p_peer133 node.cc peer.cc   peermain_000.cc -lpthread
p_peer134: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=134 -o p_peers/p_peer134 node.cc peer.cc   peermain_000.cc -lpthread
p_peer135: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=135 -o p_peers/p_peer135 node.cc peer.cc   peermain_000.cc -lpthread
p_peer136: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=136 -o p_peers/p_peer136 node.cc peer.cc   peermain_000.cc -lpthread
p_peer137: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=137 -o p_peers/p_peer137 node.cc peer.cc   peermain_000.cc -lpthread
p_peer138: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=138 -o p_peers/p_peer138 node.cc peer.cc   peermain_000.cc -lpthread
p_peer139: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=139 -o p_peers/p_peer139 node.cc peer.cc   peermain_000.cc -lpthread
p_peer140: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=140 -o p_peers/p_peer140 node.cc peer.cc   peermain_000.cc -lpthread
p_peer141: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=141 -o p_peers/p_peer141 node.cc peer.cc   peermain_000.cc -lpthread
p_peer142: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=142 -o p_peers/p_peer142 node.cc peer.cc   peermain_000.cc -lpthread
p_peer143: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=143 -o p_peers/p_peer143 node.cc peer.cc   peermain_000.cc -lpthread
p_peer144: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=144 -o p_peers/p_peer144 node.cc peer.cc   peermain_000.cc -lpthread
p_peer145: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=145 -o p_peers/p_peer145 node.cc peer.cc   peermain_000.cc -lpthread
p_peer146: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=146 -o p_peers/p_peer146 node.cc peer.cc   peermain_000.cc -lpthread
p_peer147: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=147 -o p_peers/p_peer147 node.cc peer.cc   peermain_000.cc -lpthread
p_peer148: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=148 -o p_peers/p_peer148 node.cc peer.cc   peermain_000.cc -lpthread
p_peer149: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=149 -o p_peers/p_peer149 node.cc peer.cc   peermain_000.cc -lpthread
p_peer150: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=150 -o p_peers/p_peer150 node.cc peer.cc   peermain_000.cc -lpthread
p_peer151: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=151 -o p_peers/p_peer151 node.cc peer.cc   peermain_000.cc -lpthread
p_peer152: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=152 -o p_peers/p_peer152 node.cc peer.cc   peermain_000.cc -lpthread
p_peer153: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=153 -o p_peers/p_peer153 node.cc peer.cc   peermain_000.cc -lpthread
p_peer154: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=154 -o p_peers/p_peer154 node.cc peer.cc   peermain_000.cc -lpthread
p_peer155: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=155 -o p_peers/p_peer155 node.cc peer.cc   peermain_000.cc -lpthread
p_peer156: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=156 -o p_peers/p_peer156 node.cc peer.cc   peermain_000.cc -lpthread
p_peer157: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=157 -o p_peers/p_peer157 node.cc peer.cc   peermain_000.cc -lpthread
p_peer158: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=158 -o p_peers/p_peer158 node.cc peer.cc   peermain_000.cc -lpthread
p_peer159: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=159 -o p_peers/p_peer159 node.cc peer.cc   peermain_000.cc -lpthread
p_peer160: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=160 -o p_peers/p_peer160 node.cc peer.cc   peermain_000.cc -lpthread
p_peer161: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=161 -o p_peers/p_peer161 node.cc peer.cc   peermain_000.cc -lpthread
p_peer162: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=162 -o p_peers/p_peer162 node.cc peer.cc   peermain_000.cc -lpthread
p_peer163: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=163 -o p_peers/p_peer163 node.cc peer.cc   peermain_000.cc -lpthread
p_peer164: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=164 -o p_peers/p_peer164 node.cc peer.cc   peermain_000.cc -lpthread
p_peer165: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=165 -o p_peers/p_peer165 node.cc peer.cc   peermain_000.cc -lpthread
p_peer166: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=166 -o p_peers/p_peer166 node.cc peer.cc   peermain_000.cc -lpthread
p_peer167: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=167 -o p_peers/p_peer167 node.cc peer.cc   peermain_000.cc -lpthread
p_peer168: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=168 -o p_peers/p_peer168 node.cc peer.cc   peermain_000.cc -lpthread
p_peer169: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=169 -o p_peers/p_peer169 node.cc peer.cc   peermain_000.cc -lpthread
p_peer170: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=170 -o p_peers/p_peer170 node.cc peer.cc   peermain_000.cc -lpthread
p_peer171: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=171 -o p_peers/p_peer171 node.cc peer.cc   peermain_000.cc -lpthread
p_peer172: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=172 -o p_peers/p_peer172 node.cc peer.cc   peermain_000.cc -lpthread
p_peer173: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=173 -o p_peers/p_peer173 node.cc peer.cc   peermain_000.cc -lpthread
p_peer174: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=174 -o p_peers/p_peer174 node.cc peer.cc   peermain_000.cc -lpthread
p_peer175: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=175 -o p_peers/p_peer175 node.cc peer.cc   peermain_000.cc -lpthread
p_peer176: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=176 -o p_peers/p_peer176 node.cc peer.cc   peermain_000.cc -lpthread
p_peer177: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=177 -o p_peers/p_peer177 node.cc peer.cc   peermain_000.cc -lpthread
p_peer178: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=178 -o p_peers/p_peer178 node.cc peer.cc   peermain_000.cc -lpthread
p_peer179: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=179 -o p_peers/p_peer179 node.cc peer.cc   peermain_000.cc -lpthread
p_peer180: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=180 -o p_peers/p_peer180 node.cc peer.cc   peermain_000.cc -lpthread
p_peer181: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=181 -o p_peers/p_peer181 node.cc peer.cc   peermain_000.cc -lpthread
p_peer182: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=182 -o p_peers/p_peer182 node.cc peer.cc   peermain_000.cc -lpthread
p_peer183: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=183 -o p_peers/p_peer183 node.cc peer.cc   peermain_000.cc -lpthread
p_peer184: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=184 -o p_peers/p_peer184 node.cc peer.cc   peermain_000.cc -lpthread
p_peer185: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=185 -o p_peers/p_peer185 node.cc peer.cc   peermain_000.cc -lpthread
p_peer186: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=186 -o p_peers/p_peer186 node.cc peer.cc   peermain_000.cc -lpthread
p_peer187: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=187 -o p_peers/p_peer187 node.cc peer.cc   peermain_000.cc -lpthread
p_peer188: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=188 -o p_peers/p_peer188 node.cc peer.cc   peermain_000.cc -lpthread
p_peer189: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=189 -o p_peers/p_peer189 node.cc peer.cc   peermain_000.cc -lpthread
p_peer190: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=190 -o p_peers/p_peer190 node.cc peer.cc   peermain_000.cc -lpthread
p_peer191: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=191 -o p_peers/p_peer191 node.cc peer.cc   peermain_000.cc -lpthread
p_peer192: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=192 -o p_peers/p_peer192 node.cc peer.cc   peermain_000.cc -lpthread
p_peer193: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=193 -o p_peers/p_peer193 node.cc peer.cc   peermain_000.cc -lpthread
p_peer194: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=194 -o p_peers/p_peer194 node.cc peer.cc   peermain_000.cc -lpthread
p_peer195: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=195 -o p_peers/p_peer195 node.cc peer.cc   peermain_000.cc -lpthread
p_peer196: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=196 -o p_peers/p_peer196 node.cc peer.cc   peermain_000.cc -lpthread
p_peer197: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=197 -o p_peers/p_peer197 node.cc peer.cc   peermain_000.cc -lpthread
p_peer198: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=198 -o p_peers/p_peer198 node.cc peer.cc   peermain_000.cc -lpthread
p_peer199: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=199 -o p_peers/p_peer199 node.cc peer.cc   peermain_000.cc -lpthread
p_peer200: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=200 -o p_peers/p_peer200 node.cc peer.cc   peermain_000.cc -lpthread
p_peer201: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=201 -o p_peers/p_peer201 node.cc peer.cc   peermain_000.cc -lpthread
p_peer202: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=202 -o p_peers/p_peer202 node.cc peer.cc   peermain_000.cc -lpthread
p_peer203: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=203 -o p_peers/p_peer203 node.cc peer.cc   peermain_000.cc -lpthread
p_peer204: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=204 -o p_peers/p_peer204 node.cc peer.cc   peermain_000.cc -lpthread
p_peer205: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=205 -o p_peers/p_peer205 node.cc peer.cc   peermain_000.cc -lpthread
p_peer206: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=206 -o p_peers/p_peer206 node.cc peer.cc   peermain_000.cc -lpthread
p_peer207: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=207 -o p_peers/p_peer207 node.cc peer.cc   peermain_000.cc -lpthread
p_peer208: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=208 -o p_peers/p_peer208 node.cc peer.cc   peermain_000.cc -lpthread
p_peer209: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=209 -o p_peers/p_peer209 node.cc peer.cc   peermain_000.cc -lpthread
p_peer210: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=210 -o p_peers/p_peer210 node.cc peer.cc   peermain_000.cc -lpthread
p_peer211: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=211 -o p_peers/p_peer211 node.cc peer.cc   peermain_000.cc -lpthread
p_peer212: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=212 -o p_peers/p_peer212 node.cc peer.cc   peermain_000.cc -lpthread
p_peer213: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=213 -o p_peers/p_peer213 node.cc peer.cc   peermain_000.cc -lpthread
p_peer214: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=214 -o p_peers/p_peer214 node.cc peer.cc   peermain_000.cc -lpthread
p_peer215: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=215 -o p_peers/p_peer215 node.cc peer.cc   peermain_000.cc -lpthread
p_peer216: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=216 -o p_peers/p_peer216 node.cc peer.cc   peermain_000.cc -lpthread
p_peer217: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=217 -o p_peers/p_peer217 node.cc peer.cc   peermain_000.cc -lpthread
p_peer218: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=218 -o p_peers/p_peer218 node.cc peer.cc   peermain_000.cc -lpthread
p_peer219: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=219 -o p_peers/p_peer219 node.cc peer.cc   peermain_000.cc -lpthread
p_peer220: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=220 -o p_peers/p_peer220 node.cc peer.cc   peermain_000.cc -lpthread
p_peer221: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=221 -o p_peers/p_peer221 node.cc peer.cc   peermain_000.cc -lpthread
p_peer222: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=222 -o p_peers/p_peer222 node.cc peer.cc   peermain_000.cc -lpthread
p_peer223: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=223 -o p_peers/p_peer223 node.cc peer.cc   peermain_000.cc -lpthread
p_peer224: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=224 -o p_peers/p_peer224 node.cc peer.cc   peermain_000.cc -lpthread
p_peer225: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=225 -o p_peers/p_peer225 node.cc peer.cc   peermain_000.cc -lpthread
p_peer226: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=226 -o p_peers/p_peer226 node.cc peer.cc   peermain_000.cc -lpthread
p_peer227: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=227 -o p_peers/p_peer227 node.cc peer.cc   peermain_000.cc -lpthread
p_peer228: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=228 -o p_peers/p_peer228 node.cc peer.cc   peermain_000.cc -lpthread
p_peer229: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=229 -o p_peers/p_peer229 node.cc peer.cc   peermain_000.cc -lpthread
p_peer230: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=230 -o p_peers/p_peer230 node.cc peer.cc   peermain_000.cc -lpthread
p_peer231: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=231 -o p_peers/p_peer231 node.cc peer.cc   peermain_000.cc -lpthread
p_peer232: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=232 -o p_peers/p_peer232 node.cc peer.cc   peermain_000.cc -lpthread
p_peer233: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=233 -o p_peers/p_peer233 node.cc peer.cc   peermain_000.cc -lpthread
p_peer234: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=234 -o p_peers/p_peer234 node.cc peer.cc   peermain_000.cc -lpthread
p_peer235: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=235 -o p_peers/p_peer235 node.cc peer.cc   peermain_000.cc -lpthread
p_peer236: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=236 -o p_peers/p_peer236 node.cc peer.cc   peermain_000.cc -lpthread
p_peer237: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=237 -o p_peers/p_peer237 node.cc peer.cc   peermain_000.cc -lpthread
p_peer238: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=238 -o p_peers/p_peer238 node.cc peer.cc   peermain_000.cc -lpthread
p_peer239: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=239 -o p_peers/p_peer239 node.cc peer.cc   peermain_000.cc -lpthread
p_peer240: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=240 -o p_peers/p_peer240 node.cc peer.cc   peermain_000.cc -lpthread
p_peer241: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=241 -o p_peers/p_peer241 node.cc peer.cc   peermain_000.cc -lpthread
p_peer242: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=242 -o p_peers/p_peer242 node.cc peer.cc   peermain_000.cc -lpthread
p_peer243: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=243 -o p_peers/p_peer243 node.cc peer.cc   peermain_000.cc -lpthread
p_peer244: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=244 -o p_peers/p_peer244 node.cc peer.cc   peermain_000.cc -lpthread
p_peer245: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=245 -o p_peers/p_peer245 node.cc peer.cc   peermain_000.cc -lpthread
p_peer246: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=246 -o p_peers/p_peer246 node.cc peer.cc   peermain_000.cc -lpthread
p_peer247: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=247 -o p_peers/p_peer247 node.cc peer.cc   peermain_000.cc -lpthread
p_peer248: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=248 -o p_peers/p_peer248 node.cc peer.cc   peermain_000.cc -lpthread
p_peer249: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=249 -o p_peers/p_peer249 node.cc peer.cc   peermain_000.cc -lpthread
p_peer250: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=250 -o p_peers/p_peer250 node.cc peer.cc   peermain_000.cc -lpthread
p_peer251: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=251 -o p_peers/p_peer251 node.cc peer.cc   peermain_000.cc -lpthread
p_peer252: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=252 -o p_peers/p_peer252 node.cc peer.cc   peermain_000.cc -lpthread
p_peer253: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=253 -o p_peers/p_peer253 node.cc peer.cc   peermain_000.cc -lpthread
p_peer254: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=254 -o p_peers/p_peer254 node.cc peer.cc   peermain_000.cc -lpthread
p_peer255: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=255 -o p_peers/p_peer255 node.cc peer.cc   peermain_000.cc -lpthread
p_peer256: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=256 -o p_peers/p_peer256 node.cc peer.cc   peermain_000.cc -lpthread
p_peer257: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=257 -o p_peers/p_peer257 node.cc peer.cc   peermain_000.cc -lpthread
p_peer258: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=258 -o p_peers/p_peer258 node.cc peer.cc   peermain_000.cc -lpthread
p_peer259: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=259 -o p_peers/p_peer259 node.cc peer.cc   peermain_000.cc -lpthread
p_peer260: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=260 -o p_peers/p_peer260 node.cc peer.cc   peermain_000.cc -lpthread
p_peer261: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=261 -o p_peers/p_peer261 node.cc peer.cc   peermain_000.cc -lpthread
p_peer262: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=262 -o p_peers/p_peer262 node.cc peer.cc   peermain_000.cc -lpthread
p_peer263: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=263 -o p_peers/p_peer263 node.cc peer.cc   peermain_000.cc -lpthread
p_peer264: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=264 -o p_peers/p_peer264 node.cc peer.cc   peermain_000.cc -lpthread
p_peer265: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=265 -o p_peers/p_peer265 node.cc peer.cc   peermain_000.cc -lpthread
p_peer266: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=266 -o p_peers/p_peer266 node.cc peer.cc   peermain_000.cc -lpthread
p_peer267: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=267 -o p_peers/p_peer267 node.cc peer.cc   peermain_000.cc -lpthread
p_peer268: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=268 -o p_peers/p_peer268 node.cc peer.cc   peermain_000.cc -lpthread
p_peer269: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=269 -o p_peers/p_peer269 node.cc peer.cc   peermain_000.cc -lpthread
p_peer270: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=270 -o p_peers/p_peer270 node.cc peer.cc   peermain_000.cc -lpthread
p_peer271: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=271 -o p_peers/p_peer271 node.cc peer.cc   peermain_000.cc -lpthread
p_peer272: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=272 -o p_peers/p_peer272 node.cc peer.cc   peermain_000.cc -lpthread
p_peer273: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=273 -o p_peers/p_peer273 node.cc peer.cc   peermain_000.cc -lpthread
p_peer274: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=274 -o p_peers/p_peer274 node.cc peer.cc   peermain_000.cc -lpthread
p_peer275: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=275 -o p_peers/p_peer275 node.cc peer.cc   peermain_000.cc -lpthread
p_peer276: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=276 -o p_peers/p_peer276 node.cc peer.cc   peermain_000.cc -lpthread
p_peer277: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=277 -o p_peers/p_peer277 node.cc peer.cc   peermain_000.cc -lpthread
p_peer278: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=278 -o p_peers/p_peer278 node.cc peer.cc   peermain_000.cc -lpthread
p_peer279: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=279 -o p_peers/p_peer279 node.cc peer.cc   peermain_000.cc -lpthread
p_peer280: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=280 -o p_peers/p_peer280 node.cc peer.cc   peermain_000.cc -lpthread
p_peer281: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=281 -o p_peers/p_peer281 node.cc peer.cc   peermain_000.cc -lpthread
p_peer282: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=282 -o p_peers/p_peer282 node.cc peer.cc   peermain_000.cc -lpthread
p_peer283: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=283 -o p_peers/p_peer283 node.cc peer.cc   peermain_000.cc -lpthread
p_peer284: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=284 -o p_peers/p_peer284 node.cc peer.cc   peermain_000.cc -lpthread
p_peer285: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=285 -o p_peers/p_peer285 node.cc peer.cc   peermain_000.cc -lpthread
p_peer286: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=286 -o p_peers/p_peer286 node.cc peer.cc   peermain_000.cc -lpthread
p_peer287: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=287 -o p_peers/p_peer287 node.cc peer.cc   peermain_000.cc -lpthread
p_peer288: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=288 -o p_peers/p_peer288 node.cc peer.cc   peermain_000.cc -lpthread
p_peer289: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=289 -o p_peers/p_peer289 node.cc peer.cc   peermain_000.cc -lpthread
p_peer290: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=290 -o p_peers/p_peer290 node.cc peer.cc   peermain_000.cc -lpthread
p_peer291: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=291 -o p_peers/p_peer291 node.cc peer.cc   peermain_000.cc -lpthread
p_peer292: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=292 -o p_peers/p_peer292 node.cc peer.cc   peermain_000.cc -lpthread
p_peer293: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=293 -o p_peers/p_peer293 node.cc peer.cc   peermain_000.cc -lpthread
p_peer294: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=294 -o p_peers/p_peer294 node.cc peer.cc   peermain_000.cc -lpthread
p_peer295: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=295 -o p_peers/p_peer295 node.cc peer.cc   peermain_000.cc -lpthread
p_peer296: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=296 -o p_peers/p_peer296 node.cc peer.cc   peermain_000.cc -lpthread
p_peer297: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=297 -o p_peers/p_peer297 node.cc peer.cc   peermain_000.cc -lpthread
p_peer298: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=298 -o p_peers/p_peer298 node.cc peer.cc   peermain_000.cc -lpthread
p_peer299: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=299 -o p_peers/p_peer299 node.cc peer.cc   peermain_000.cc -lpthread
p_peer300: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=300 -o p_peers/p_peer300 node.cc peer.cc   peermain_000.cc -lpthread
p_peer301: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=301 -o p_peers/p_peer301 node.cc peer.cc   peermain_000.cc -lpthread
p_peer302: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=302 -o p_peers/p_peer302 node.cc peer.cc   peermain_000.cc -lpthread
p_peer303: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=303 -o p_peers/p_peer303 node.cc peer.cc   peermain_000.cc -lpthread
p_peer304: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=304 -o p_peers/p_peer304 node.cc peer.cc   peermain_000.cc -lpthread
p_peer305: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=305 -o p_peers/p_peer305 node.cc peer.cc   peermain_000.cc -lpthread
p_peer306: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=306 -o p_peers/p_peer306 node.cc peer.cc   peermain_000.cc -lpthread
p_peer307: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=307 -o p_peers/p_peer307 node.cc peer.cc   peermain_000.cc -lpthread
p_peer308: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=308 -o p_peers/p_peer308 node.cc peer.cc   peermain_000.cc -lpthread
p_peer309: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=309 -o p_peers/p_peer309 node.cc peer.cc   peermain_000.cc -lpthread
p_peer310: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=310 -o p_peers/p_peer310 node.cc peer.cc   peermain_000.cc -lpthread
p_peer311: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=311 -o p_peers/p_peer311 node.cc peer.cc   peermain_000.cc -lpthread
p_peer312: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=312 -o p_peers/p_peer312 node.cc peer.cc   peermain_000.cc -lpthread
p_peer313: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=313 -o p_peers/p_peer313 node.cc peer.cc   peermain_000.cc -lpthread
p_peer314: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=314 -o p_peers/p_peer314 node.cc peer.cc   peermain_000.cc -lpthread
p_peer315: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=315 -o p_peers/p_peer315 node.cc peer.cc   peermain_000.cc -lpthread
p_peer316: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=316 -o p_peers/p_peer316 node.cc peer.cc   peermain_000.cc -lpthread
p_peer317: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=317 -o p_peers/p_peer317 node.cc peer.cc   peermain_000.cc -lpthread
p_peer318: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=318 -o p_peers/p_peer318 node.cc peer.cc   peermain_000.cc -lpthread
p_peer319: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=319 -o p_peers/p_peer319 node.cc peer.cc   peermain_000.cc -lpthread
p_peer320: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=320 -o p_peers/p_peer320 node.cc peer.cc   peermain_000.cc -lpthread
p_peer321: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=321 -o p_peers/p_peer321 node.cc peer.cc   peermain_000.cc -lpthread
p_peer322: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=322 -o p_peers/p_peer322 node.cc peer.cc   peermain_000.cc -lpthread
p_peer323: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=323 -o p_peers/p_peer323 node.cc peer.cc   peermain_000.cc -lpthread
p_peer324: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=324 -o p_peers/p_peer324 node.cc peer.cc   peermain_000.cc -lpthread
p_peer325: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=325 -o p_peers/p_peer325 node.cc peer.cc   peermain_000.cc -lpthread
p_peer326: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=326 -o p_peers/p_peer326 node.cc peer.cc   peermain_000.cc -lpthread
p_peer327: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=327 -o p_peers/p_peer327 node.cc peer.cc   peermain_000.cc -lpthread
p_peer328: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=328 -o p_peers/p_peer328 node.cc peer.cc   peermain_000.cc -lpthread
p_peer329: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=329 -o p_peers/p_peer329 node.cc peer.cc   peermain_000.cc -lpthread
p_peer330: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=330 -o p_peers/p_peer330 node.cc peer.cc   peermain_000.cc -lpthread
p_peer331: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=331 -o p_peers/p_peer331 node.cc peer.cc   peermain_000.cc -lpthread
p_peer332: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=332 -o p_peers/p_peer332 node.cc peer.cc   peermain_000.cc -lpthread
p_peer333: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=333 -o p_peers/p_peer333 node.cc peer.cc   peermain_000.cc -lpthread
p_peer334: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=334 -o p_peers/p_peer334 node.cc peer.cc   peermain_000.cc -lpthread
p_peer335: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=335 -o p_peers/p_peer335 node.cc peer.cc   peermain_000.cc -lpthread
p_peer336: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=336 -o p_peers/p_peer336 node.cc peer.cc   peermain_000.cc -lpthread
p_peer337: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=337 -o p_peers/p_peer337 node.cc peer.cc   peermain_000.cc -lpthread
p_peer338: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=338 -o p_peers/p_peer338 node.cc peer.cc   peermain_000.cc -lpthread
p_peer339: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=339 -o p_peers/p_peer339 node.cc peer.cc   peermain_000.cc -lpthread
p_peer340: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=340 -o p_peers/p_peer340 node.cc peer.cc   peermain_000.cc -lpthread
p_peer341: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=341 -o p_peers/p_peer341 node.cc peer.cc   peermain_000.cc -lpthread
p_peer342: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=342 -o p_peers/p_peer342 node.cc peer.cc   peermain_000.cc -lpthread
p_peer343: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=343 -o p_peers/p_peer343 node.cc peer.cc   peermain_000.cc -lpthread
p_peer344: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=344 -o p_peers/p_peer344 node.cc peer.cc   peermain_000.cc -lpthread
p_peer345: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=345 -o p_peers/p_peer345 node.cc peer.cc   peermain_000.cc -lpthread
p_peer346: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=346 -o p_peers/p_peer346 node.cc peer.cc   peermain_000.cc -lpthread
p_peer347: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=347 -o p_peers/p_peer347 node.cc peer.cc   peermain_000.cc -lpthread
p_peer348: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=348 -o p_peers/p_peer348 node.cc peer.cc   peermain_000.cc -lpthread
p_peer349: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=349 -o p_peers/p_peer349 node.cc peer.cc   peermain_000.cc -lpthread
p_peer350: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=350 -o p_peers/p_peer350 node.cc peer.cc   peermain_000.cc -lpthread
p_peer351: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=351 -o p_peers/p_peer351 node.cc peer.cc   peermain_000.cc -lpthread
p_peer352: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=352 -o p_peers/p_peer352 node.cc peer.cc   peermain_000.cc -lpthread
p_peer353: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=353 -o p_peers/p_peer353 node.cc peer.cc   peermain_000.cc -lpthread
p_peer354: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=354 -o p_peers/p_peer354 node.cc peer.cc   peermain_000.cc -lpthread
p_peer355: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=355 -o p_peers/p_peer355 node.cc peer.cc   peermain_000.cc -lpthread
p_peer356: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=356 -o p_peers/p_peer356 node.cc peer.cc   peermain_000.cc -lpthread
p_peer357: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=357 -o p_peers/p_peer357 node.cc peer.cc   peermain_000.cc -lpthread
p_peer358: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=358 -o p_peers/p_peer358 node.cc peer.cc   peermain_000.cc -lpthread
p_peer359: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=359 -o p_peers/p_peer359 node.cc peer.cc   peermain_000.cc -lpthread
p_peer360: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=360 -o p_peers/p_peer360 node.cc peer.cc   peermain_000.cc -lpthread
p_peer361: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=361 -o p_peers/p_peer361 node.cc peer.cc   peermain_000.cc -lpthread
p_peer362: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=362 -o p_peers/p_peer362 node.cc peer.cc   peermain_000.cc -lpthread
p_peer363: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=363 -o p_peers/p_peer363 node.cc peer.cc   peermain_000.cc -lpthread
p_peer364: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=364 -o p_peers/p_peer364 node.cc peer.cc   peermain_000.cc -lpthread
p_peer365: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=365 -o p_peers/p_peer365 node.cc peer.cc   peermain_000.cc -lpthread
p_peer366: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=366 -o p_peers/p_peer366 node.cc peer.cc   peermain_000.cc -lpthread
p_peer367: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=367 -o p_peers/p_peer367 node.cc peer.cc   peermain_000.cc -lpthread
p_peer368: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=368 -o p_peers/p_peer368 node.cc peer.cc   peermain_000.cc -lpthread
p_peer369: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=369 -o p_peers/p_peer369 node.cc peer.cc   peermain_000.cc -lpthread
p_peer370: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=370 -o p_peers/p_peer370 node.cc peer.cc   peermain_000.cc -lpthread
p_peer371: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=371 -o p_peers/p_peer371 node.cc peer.cc   peermain_000.cc -lpthread
p_peer372: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=372 -o p_peers/p_peer372 node.cc peer.cc   peermain_000.cc -lpthread
p_peer373: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=373 -o p_peers/p_peer373 node.cc peer.cc   peermain_000.cc -lpthread
p_peer374: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=374 -o p_peers/p_peer374 node.cc peer.cc   peermain_000.cc -lpthread
p_peer375: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=375 -o p_peers/p_peer375 node.cc peer.cc   peermain_000.cc -lpthread
p_peer376: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=376 -o p_peers/p_peer376 node.cc peer.cc   peermain_000.cc -lpthread
p_peer377: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=377 -o p_peers/p_peer377 node.cc peer.cc   peermain_000.cc -lpthread
p_peer378: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=378 -o p_peers/p_peer378 node.cc peer.cc   peermain_000.cc -lpthread
p_peer379: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=379 -o p_peers/p_peer379 node.cc peer.cc   peermain_000.cc -lpthread
p_peer380: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=380 -o p_peers/p_peer380 node.cc peer.cc   peermain_000.cc -lpthread
p_peer381: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=381 -o p_peers/p_peer381 node.cc peer.cc   peermain_000.cc -lpthread
p_peer382: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=382 -o p_peers/p_peer382 node.cc peer.cc   peermain_000.cc -lpthread
p_peer383: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=383 -o p_peers/p_peer383 node.cc peer.cc   peermain_000.cc -lpthread
p_peer384: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=384 -o p_peers/p_peer384 node.cc peer.cc   peermain_000.cc -lpthread
p_peer385: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=385 -o p_peers/p_peer385 node.cc peer.cc   peermain_000.cc -lpthread
p_peer386: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=386 -o p_peers/p_peer386 node.cc peer.cc   peermain_000.cc -lpthread
p_peer387: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=387 -o p_peers/p_peer387 node.cc peer.cc   peermain_000.cc -lpthread
p_peer388: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=388 -o p_peers/p_peer388 node.cc peer.cc   peermain_000.cc -lpthread
p_peer389: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=389 -o p_peers/p_peer389 node.cc peer.cc   peermain_000.cc -lpthread
p_peer390: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=390 -o p_peers/p_peer390 node.cc peer.cc   peermain_000.cc -lpthread
p_peer391: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=391 -o p_peers/p_peer391 node.cc peer.cc   peermain_000.cc -lpthread
p_peer392: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=392 -o p_peers/p_peer392 node.cc peer.cc   peermain_000.cc -lpthread
p_peer393: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=393 -o p_peers/p_peer393 node.cc peer.cc   peermain_000.cc -lpthread
p_peer394: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=394 -o p_peers/p_peer394 node.cc peer.cc   peermain_000.cc -lpthread
p_peer395: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=395 -o p_peers/p_peer395 node.cc peer.cc   peermain_000.cc -lpthread
p_peer396: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=396 -o p_peers/p_peer396 node.cc peer.cc   peermain_000.cc -lpthread
p_peer397: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=397 -o p_peers/p_peer397 node.cc peer.cc   peermain_000.cc -lpthread
p_peer398: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=398 -o p_peers/p_peer398 node.cc peer.cc   peermain_000.cc -lpthread
p_peer399: node.cc peer.cc peermain_000.cc
	g++  -g -rdynamic -D PEER_ID=399 -o p_peers/p_peer399 node.cc peer.cc   peermain_000.cc -lpthread

clean:
	rm -rf p_server pgetip p_peers/p_peer*