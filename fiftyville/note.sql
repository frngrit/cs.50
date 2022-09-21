SELECT crime_scene_reports.year,crime_scene_reports.month,crime_scene_reports.day FROM crime_scene_reports, atm_transactions
WHERE crime_scene_reports.year = atm_transactions.year
AND crime_scene_reports.month = atm_transactions.month
AND crime_scene_reports.day = atm_transactions.day
AND crime_scene_reports.street = atm_transactions.atm_location;

+------+-------+-----+
| year | month | day |
+------+-------+-----+
| 2021 | 8     | 1   |

SELECT * FROM crime_scene_reports WHERE year = 2021 AND month = 8 AND day = 1;
+-----+------+-------+-----+---------------+-------------------------------------------------------------------+
| id  | year | month | day |    street     |                            description                            |
+-----+------+-------+-----+---------------+-------------------------------------------------------------------+
| 301 | 2021 | 8     | 1   | Carvalho Road | Vandalism took place at 13:52. One person witnessed the incident. |
+-----+------+-------+-----+---------------+-------------------------------------------------------------------+

SELECT * FROM interviews  WHERE year = 2021 AND month = 8 AND day = 1;
+-----+--------+------+-------+-----+---------------------------------------------------------------+
| id  |  name  | year | month | day |                          transcript                           |
+-----+--------+------+-------+-----+---------------------------------------------------------------+
| 164 | Teresa | 2021 | 8     | 1   | “‘Come, man, come, only three minutes, or it won’t be legal.’ |
+-----+--------+------+-------+-----+---------------------------------------------------------------+

SELECT * FROM atm_transactions WHERE year = 2021 AND month = 8 AND day = 1 AND atm_location = "Carvalho Road" AND transaction_type = "deposit";
+------+----------------+------+-------+-----+---------------+------------------+--------+
|  id  | account_number | year | month | day | atm_location  | transaction_type | amount |
+------+----------------+------+-------+-----+---------------+------------------+--------+
| 1069 | 33637883       | 2021 | 8     | 1   | Carvalho Road | deposit          | 10     |
| 1075 | 19531272       | 2021 | 8     | 1   | Carvalho Road | deposit          | 60     |
| 1084 | 17171330       | 2021 | 8     | 1   | Carvalho Road | deposit          | 35     |
| 1087 | 24064261       | 2021 | 8     | 1   | Carvalho Road | deposit          | 65     |
| 1098 | 99031604       | 2021 | 8     | 1   | Carvalho Road | deposit          | 75     |
| 1105 | 89843009       | 2021 | 8     | 1   | Carvalho Road | deposit          | 20     |
| 1116 | 17161820       | 2021 | 8     | 1   | Carvalho Road | deposit          | 60     |
| 1127 | 13156006       | 2021 | 8     | 1   | Carvalho Road | deposit          | 90     |
| 1142 | 26191313       | 2021 | 8     | 1   | Carvalho Road | deposit          | 15     |
| 1166 | 55322348       | 2021 | 8     | 1   | Carvalho Road | deposit          | 5      |
| 1184 | 32179718       | 2021 | 8     | 1   | Carvalho Road | deposit          | 55     |
| 1186 | 39774254       | 2021 | 8     | 1   | Carvalho Road | deposit          | 40     |
| 1196 | 70504954       | 2021 | 8     | 1   | Carvalho Road | deposit          | 35     |
| 1201 | 39696970       | 2021 | 8     | 1   | Carvalho Road | deposit          | 80     |
| 1242 | 21149684       | 2021 | 8     | 1   | Carvalho Road | deposit          | 35     |
| 1245 | 92647903       | 2021 | 8     | 1   | Carvalho Road | deposit          | 10     |
| 1247 | 46222318       | 2021 | 8     | 1   | Carvalho Road | deposit          | 50     |
| 1261 | 32134232       | 2021 | 8     | 1   | Carvalho Road | deposit          | 65     |
| 1269 | 21149684       | 2021 | 8     | 1   | Carvalho Road | deposit          | 10     |
| 1283 | 16194980       | 2021 | 8     | 1   | Carvalho Road | deposit          | 40     |
| 1300 | 75571594       | 2021 | 8     | 1   | Carvalho Road | deposit          | 10     |
| 1310 | 76849114       | 2021 | 8     | 1   | Carvalho Road | deposit          | 100    |
| 1315 | 93622979       | 2021 | 8     | 1   | Carvalho Road | deposit          | 35     |
| 1316 | 65190958       | 2021 | 8     | 1   | Carvalho Road | deposit          | 10     |
| 1331 | 95773068       | 2021 | 8     | 1   | Carvalho Road | deposit          | 90     |
+------+----------------+------+-------+-----+---------------+------------------+--------+


SELECT * FROM atm_transactions WHERE year = 2021 AND month = 8 AND day = 1 AND atm_location = "Carvalho Road" AND transaction_type = "withdraw";
+------+----------------+------+-------+-----+---------------+------------------+--------+
|  id  | account_number | year | month | day | atm_location  | transaction_type | amount |
+------+----------------+------+-------+-----+---------------+------------------+--------+
| 1072 | 26249951       | 2021 | 8     | 1   | Carvalho Road | withdraw         | 5      |
| 1088 | 33528144       | 2021 | 8     | 1   | Carvalho Road | withdraw         | 40     |
| 1101 | 76896546       | 2021 | 8     | 1   | Carvalho Road | withdraw         | 5      |
| 1123 | 65190958       | 2021 | 8     | 1   | Carvalho Road | withdraw         | 20     |
| 1126 | 40981669       | 2021 | 8     | 1   | Carvalho Road | withdraw         | 20     |
| 1134 | 18363023       | 2021 | 8     | 1   | Carvalho Road | withdraw         | 25     |
| 1150 | 47746428       | 2021 | 8     | 1   | Carvalho Road | withdraw         | 30     |
| 1151 | 28579039       | 2021 | 8     | 1   | Carvalho Road | withdraw         | 30     |
| 1152 | 33528144       | 2021 | 8     | 1   | Carvalho Road | withdraw         | 35     |
| 1163 | 52457779       | 2021 | 8     | 1   | Carvalho Road | withdraw         | 45     |
| 1171 | 71305903       | 2021 | 8     | 1   | Carvalho Road | withdraw         | 65     |
| 1172 | 55656186       | 2021 | 8     | 1   | Carvalho Road | withdraw         | 90     |
| 1191 | 15911007       | 2021 | 8     | 1   | Carvalho Road | withdraw         | 60     |
| 1194 | 70992522       | 2021 | 8     | 1   | Carvalho Road | withdraw         | 65     |
| 1203 | 41935128       | 2021 | 8     | 1   | Carvalho Road | withdraw         | 20     |
| 1212 | 69278040       | 2021 | 8     | 1   | Carvalho Road | withdraw         | 70     |
| 1214 | 92206742       | 2021 | 8     | 1   | Carvalho Road | withdraw         | 35     |
| 1243 | 96352349       | 2021 | 8     | 1   | Carvalho Road | withdraw         | 100    |
| 1252 | 36438351       | 2021 | 8     | 1   | Carvalho Road | withdraw         | 65     |
| 1266 | 67735369       | 2021 | 8     | 1   | Carvalho Road | withdraw         | 80     |
| 1293 | 83997425       | 2021 | 8     | 1   | Carvalho Road | withdraw         | 25     |
| 1295 | 56171033       | 2021 | 8     | 1   | Carvalho Road | withdraw         | 55     |
| 1304 | 32747120       | 2021 | 8     | 1   | Carvalho Road | withdraw         | 60     |
+------+----------------+------+-------+-----+---------------+------------------+--------+