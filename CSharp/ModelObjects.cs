using System;
using System.Collections;
using System.Collections.Generic;

namespace export
{
    public class StoreEvent : Product
    {
        private Store Store { get; set; }

        public StoreEvent(string name, string type, Store store, Price price) : base(name, type, 0, price)
        {
            SetLocation(store);
        }

        public void SetLocation(Store store)
        {
            this.Store = store;
            store.AddStockedItems(this);
        }
        public override bool IsEvent()
        {
            return true;
        }
    }

    public class Product
    {
        public string Name { get; set; }
        public string Id { get; set; }
        public int Weight { get; set; }
        public Price Price { get; set; }

        public Product(string name, string type, int weight, Price price)
        {
            this.Name = name;
            this.Id = type;
            this.Weight = weight;
            this.Price = price;
        }

        public virtual bool IsEvent()
        {
            return false;
        }
    }

    public class Price
    {

        public Price(double amount, string currency)
        {
            this.Amount = amount;
            this.Currency = currency;
        }

        public double Amount { get; set; }
        public string Currency { get; set; }

        public double GetAmountInCurrency(string currency)
        {
            return this.Amount;
        }
    }

    public class Store
    {
        public string Name { get; set; }
        public string Id { get; set; }

        private readonly Dictionary<string, Product> _itemsInStock = new Dictionary<string, Product>();


        public void AddStockedItems(params Product[] products)
        {
            foreach (var product in products)
            {
                this._itemsInStock.Add(product.Name, product);
            }
        }
    }

    public class Order
    {
        public readonly IList<Product> Products = new List<Product>();

        public string Id { get; set; }
        public DateTime Date { get; set; }
        public Store Store { get; set; }

        public double TotalDollars()
        {
            return 0;
        }
    }

}


