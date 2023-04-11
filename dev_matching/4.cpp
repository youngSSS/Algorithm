-- 코드를 입력하세요
SELECT id, name
from SUBWAY_STATIONS
where id in (
	select station_id from LINE_ROUTES where station_id not in (
	select station_id from LINE_ROUTES where line_color in ("Red", "Green")
)
)
or
id in (
	select s.id
	from SUBWAY_STATIONS as s left outer join LINE_ROUTES as l on s.id = l.station_id
where l.line_color is null
)
order by id;