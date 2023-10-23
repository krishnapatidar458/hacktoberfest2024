const products = [];

function addProduct(name, price) {
    if (name && price) {
        const product = { name: name, price: price };
        products.push(product);
    } else {
        alert("Please enter product name and price.");
    }
}

function removeProduct(index) {
    products.splice(index, 1);
}

function updateProductList() {
    const productList = document.getElementById("product-list");
    productList.innerHTML = ''; // Clear the existing list

    products.forEach((product, index) => {
        const row = document.createElement("tr");
        row.innerHTML = `
            <td>${index + 1}</td>
            <td>${product.name.toLowerCase()}</td>
            <td>${product.price}</td>
            <td><button onclick="removeProduct(${index})">Delete</button></td>
        `;
        productList.appendChild(row);
    });
}

function addProductFromForm() {
    const name = document.getElementById("name").value;
    const price = document.getElementById("price").value;
    addProduct(name, price);
    updateProductList();
    // Clear input fields
    document.getElementById("name").value = '';
    document.getElementById("price").value = '';
}

updateProductList();
