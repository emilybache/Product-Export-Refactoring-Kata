from sample_model_objects import RecentOrder, OldOrder
from xml_exporter import *
from approvaltests import verify


def test_export_full():
    xml = export_full([RecentOrder, OldOrder])
    verify(xml)
