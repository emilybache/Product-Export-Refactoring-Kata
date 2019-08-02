from sample_model_objects import RecentOrder
from xml_exporter import *
from approvaltests import verify


def test_export_full():
    xml = export_full([RecentOrder])
    verify(xml)
